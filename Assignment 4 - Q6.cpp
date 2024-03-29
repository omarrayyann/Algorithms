#include <iostream>
#include <vector>
#include <climits>
#include <stack>
#include <queue>

using namespace std;

bool bfs(vector<vector<int>> &graph, vector<int> &parent, int starting, int goal)
{

    vector<bool> visited;
    visited.resize(graph.size(), false);

    queue<int> q;
    q.push(starting);
    visited.at(starting) = true;
    parent.at(starting) = -1;

    while (!q.empty())
    {
        int from = q.front();
        q.pop();

        for (int to = 0; to < graph.size(); to++)
        {

            if (visited.at(to) == false && graph.at(from).at(to) > 0)
            {
                parent.at(to) = from;
                visited.at(to) = true;
                q.push(to);

                if (to == goal)
                {
                    return true;
                }
            }
        }
    }

    return false;
}

int ford_fulkerson(vector<vector<int>> &graph, int starting, int goal)
{
    vector<vector<int>> residual_graph = graph;
    vector<int> parent(graph.size(), -1);

    int max_flow = 0;

    while (bfs(residual_graph, parent, starting, goal))
    {
        // Finding the bottlneck
        int path_flow = INT_MAX;

        int current_node = goal;
        while (current_node != starting)
        {

            int parent_node = parent.at(current_node);

            path_flow = min(path_flow, residual_graph.at(parent_node).at(current_node));
            current_node = parent.at(current_node);
        }

        current_node = goal;
        while (current_node != starting)
        {
            int parent_node = parent.at(current_node);
            residual_graph.at(parent_node).at(current_node) -= path_flow;
            residual_graph.at(current_node).at(parent_node) += path_flow;
            current_node = parent.at(current_node);
        }

        max_flow += path_flow;
    }

    for(int i = 0; i<residual_graph.size(); i++){
        for(int j = 0; j<residual_graph.size(); i++){
            cout << graph.at(i).at(j) << " ";
        }
        cout << endl;
    }

    return max_flow;
}

int main()
{
    vector<vector<int>> graph = {
        {0, 36, 11, 8, 50, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, INT_MAX, 0, INT_MAX, 0, 0},
        {0, 0, 0, 0, 0, 0, INT_MAX, INT_MAX, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, INT_MAX, 0, 0},
        {0, 0, 0, 0, 0, INT_MAX, INT_MAX, INT_MAX, INT_MAX, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 42},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 8},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 3},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 45},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    };
    cout << "The maximum possible flow is "
         << ford_fulkerson(graph, 0, 9) << endl;
}