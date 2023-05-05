#include <iostream>
#include <vector>
using namespace std;

int *mem;

int max_independent_set_value(vector<int> weights, int i)
{
    if (i >= weights.size())
    {
        return 0;
    }
    if (mem[i] != -1)
    {
        return mem[i];
    }
    int ans = max(max_independent_set_value(weights, i + 1), weights.at(i) + max_independent_set_value(weights, i + 2));
    mem[i] = ans;
    return ans;
}

vector<int> max_independent_set_vertices(vector<int> weight)
{
    vector<int> vertices;
    int sum = 0;
    int i = weight.size() - 1;
    while (i >= 0)
    {
        if ((mem[i] - weight[i] - sum) == 0)
        {
            vertices.push_back(i);
            sum += weight[i];
            i -= 2;
        }
        else
        {
            i--;
        }
    }
    return vertices;
}

int main()
{
    vector<int> weight = {1, 4, 5, 2, 4, 5, 4, 3, 2, 4};
    mem = new int[weight.size()];
    for (int i = 0; i < weight.size(); i++)
    {
        mem[i] = -1;
    }
    // these functions have to be ran in this order
    cout << max_independent_set_value(weight, 0) << endl;
    vector<int> vertices = max_independent_set_vertices(weight);
    for (auto vertex : vertices)
    {
        cout << vertex << " ";
    }
    cout << endl;
}
