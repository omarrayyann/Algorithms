#include <iostream>
#include <vector>
#include <climits>

using namespace std;

int getMinimumUnvisited(vector<bool> &visited, vector<int> &distances)
{

    int minimumIndex = 0;
    int minDistance = INT_MAX;

    for (int i = 0; i < distances.size(); i++)
    {
        if (distances.at(i) < minDistance && !visited.at(i))
        {
            minimumIndex = i;
            minDistance = distances.at(i);
        }
    }
    return minimumIndex;
}

vector<int> dijkstra(vector<vector<int>> &graph, int starting)
{

    vector<bool> visited;
    visited.resize(graph.size(), false);
    vector<int> distances;
    distances.resize(graph.size(), INT_MAX);
    distances.at(starting) = 0;

    for (int i = 0; i < graph.size(); i++)
    {
        int current = getMinimumUnvisited(visited, distances);
        visited.at(current) = true;
        for (int j = 0; j < graph.at(0).size(); j++)
        {
            if (graph.at(i).at(j) != 0 && !visited.at(j))
            {
                distances.at(j) = min(distances.at(j), distances.at(i) + graph.at(i).at(j));
            }
        }
    }

    return distances;
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