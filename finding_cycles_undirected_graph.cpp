#include <iostream>
#include <vector>
#include <climits>

using namespace std;

vector<vector<int>> cycles;

void DFS_Cycles_Finder(vector<vector<int>> &graph, vector<int> &visited, vector<int> &parents, int node, int p)
{
    // visited status 0: unvisited
    // visited status 1: partially visited
    // visited status 2: fully visited

    if (visited.at(node) == 0)
    {
        parents.at(node) = p;
        visited.at(node) = 1;
        for (auto neighbor : graph.at(node))
        {
            if (neighbor != parents.at(node))
            {
                DFS_Cycles_Finder(graph, visited, parents, neighbor, node);
            }
        }
        visited.at(node) = 2;
    }
    else if (visited.at(node) == 1)
    {
        vector<int> newCycle;
        int currentNode = p;
        newCycle.push_back(currentNode);
        while (currentNode != node)
        {
            currentNode = parents.at(currentNode);
            newCycle.push_back(currentNode);
        }
        cycles.push_back(newCycle);
    }
}

int main()
{
    vector<vector<int>> graph = {
        {1, 2},
        {0, 3},
        {0, 3},
        {1, 2, 4},
        {3, 5, 6},
        {4, 6},
        {4, 5}};
    vector<int> visited;
    visited.resize(graph.size(), 0);
    vector<int> parents;
    parents.resize(graph.size(), -1);

    DFS_Cycles_Finder(graph, visited, parents, 0, 0);

    for (int i = 0; i < cycles.size(); i++)
    {
        for (int j = 0; j < cycles.at(i).size(); j++)
        {
            cout << cycles.at(i).at(j) << " ";
        }
        cout << endl;
    }
}