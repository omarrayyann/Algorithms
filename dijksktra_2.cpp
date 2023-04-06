#include <iostream>
#include <vector>
#include <climits>

using namespace std;

int getMinimumUnvisited(vector<bool> &visited, vector<int> &distances)
{
    int minimumIndex = -1;
    for (int i = 0; i < visited.size(); i++)
    {
        if (minimumIndex == -1 || distances.at(i) < distances.at(minimumIndex))
        {
            minimumIndex = i;
        }
    }
    return minimumIndex;
}

vector<int> dijkstra(vector<vector<int>> &graph, int starting)
{

    vector<int> distances;
    distances.resize(graph.size(), INT_MAX);
    vector<bool> visited;
    visited.resize(graph.size(), false);
    distances.at(starting) = 0;

    for (int j = 0; j < graph.size(); j++)
    {
        int current = getMinimumUnvisited(visited, distances);
        visited.at(current) = true;

        for (int i = 0; i < graph.size(); i++)
        {
            if (graph.at(current).at(i) && distances.at(current) + graph.at(current).at(i) < distances.at(i))
            {
                distances.at(i) = graph.at(current).at(i) + distances.at(current);
            }
        }
    }
}

int main()
{

    vector<vector<int>> graph = {
        {0, 10, 15, 0, 0, 0},
        {10, 0, 0, 12, 0, 15},
        {15, 0, 0, 0, 10, 0},
        {0, 12, 0, 0, 1, 1},
        {0, 0, 10, 1, 0, 5},
        {0, 15, 0, 1, 5, 0},
    };

    vector<int> ans = dijkstra(graph, 0);

    for (int i = 0; i < ans.size(); i++)
    {
        cout << i << ": " << ans.at(i) << endl;
    }
}