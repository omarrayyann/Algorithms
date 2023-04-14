#include <iostream>
#include <vector>
#include <climits>

using namespace std;

vector<vector<int>> mem;

int knapSack(vector<int> &values, vector<int> &weights, int weight, int index)
{
    if (weight == 0 || index == -1)
    {
        return 0;
    }

    if (mem.at(index).at(weight) != -1)
    {
        return mem.at(index).at(weight);
    }

    if (weights.at(index) <= weight)
    {
        int ans = max(values.at(index) + knapSack(values, weights, weight - weights.at(index), index - 1), knapSack(values, weights, weight, index - 1));
        mem.at(index).at(weight) = ans;
        return ans;
    }
    else
    {
        int ans = knapSack(values, weights, weight, index - 1);
        mem.at(index).at(weight) = ans;
        return ans;
    }
}

int main()
{

    vector<int> values = {60, 100, 120};
    vector<int> weights = {10, 20, 30};

    int maxWeight = 50;

    vector<int> temp;
    temp.resize(maxWeight, -1);
    mem.resize(values.size(), temp);

    cout << "MAX VALUE: " << knapSack(values, weights, maxWeight, values.size() - 1) << endl;
}