#include <iostream>
#include <vector>
using namespace std;

int *mem;

int longest_path_length(vector<vector<int>> graph, int i)
{
    if (graph.at(i).size() == 0)
    {
        return 0;
    }
    if (mem[i] != -1)
    {
        return mem[i];
    }
    int answer = 0;
    for (auto nodes : graph.at(i))
    {
        answer = max(answer, 1 + longest_path_length(graph, nodes));
    }
    mem[i] = answer;
    return answer;
}

int main()
{
    vector<vector<int>> graph = {
        {1, 2},
        {5},
        {3},
        {4},
        {5},
        {}};

    mem = new int[graph.size()];

    for (int i = 0; i < graph.size(); i++)
    {
        mem[i] = -1;
    }

    cout << longest_path_length(graph, 0) << endl;
}
