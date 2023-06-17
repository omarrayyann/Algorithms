#include <iostream>
#include <vector>
#include <climits>

using namespace std;

// {From, To}, Cost
typedef pair<vector<int>, int> edge;

vector<int> bellman_ford(vector<vector<int>> &graph, int starting)
{

    vector<int> distances;
    distances.resize(graph.size(), INT_MAX);
    distances.at(starting) = 0;

    vector<vector<int>> edges;

    for (int i = 0; i < graph.size(); i++)
    {
        for (int j = 0; j < graph.at(0).size(); j++)
        {
            if (graph.at(i).at(j) != 0)
            {
                edges.push_back({i, j});
            }
        }
    }

    // Relaxing the edges until no changes occur in an iteration (n-1) in the worst case
    for (int i = 0; i < graph.size(); i++)
    {
        bool change = false;
        for (auto edge : edges)
        {
            int from = edge[0];
            int to = edge[1];
            int weight = graph.at(from).at(to);
            if (distances[from] != INT_MAX && distances[from] + weight < distances[to])
            {
                distances[to] = distances[from] + weight;
                change = true;
            }
        }
        if (!change)
        {
            break;
        }
    }

    return distances;
}

int main()
{

    vector<vector<int>> graph = {
        {0, 1, 0, 2, 0}, {0, 0, 2, 0, 0}, {0, 0, 0, 0, 8}, {0, 0, 0, 0, 3}, {0, 0, 0, 0, 0}};

    vector<int> ans = bellman_ford(graph, 0);

    for (int i = 0; i < ans.size(); i++)
    {
        cout << i << ": " << ans.at(i) << endl;
    }
}