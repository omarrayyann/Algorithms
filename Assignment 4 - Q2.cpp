#include <iostream>
#include <vector>
#include <stack>
using namespace std;

pair<int, vector<int>> *mem;
stack<int> current;

pair<int, vector<int>> maxWeightIndependentSet(vector<int> weights, int i)
{
    if (mem[i].first != -1)
    {
        return mem[i];
    }
    if (i >= weights.size())
    {
        vector<int> temp;
        return make_pair(0, vector<int>());
    }
    pair<int, vector<int>> option1 = maxWeightIndependentSet(weights, i + 1);
    pair<int, vector<int>> option2 = maxWeightIndependentSet(weights, i + 2);

    option2.first += weights.at(i);
    option2.second.push_back(i);

    if (option2.first > option1.first)
    {
        mem[i] = option2;
        return option2;
    }
    mem[i] = option1;
    return option1;
}

int main()
{
    vector<int> path = {1, 8, 6, 3, 6};
    mem = new pair<int, vector<int>>[path.size() + 1];
    for (int i = 0; i < path.size() + 1; i++)
    {
        mem[i].first = -1;
    }
    cout << maxWeightIndependentSet(path, 0).first << endl;
}
