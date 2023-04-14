#include <iostream>
#include <vector>
#include <climits>
#include <stack>

using namespace std;

void DFS(vector<vector<int>> &graph, int vertix);
vector<bool> visited;
stack<int> finished;

// assuming the graph is ascylic
void topological_sorting(vector<vector<int>> &graph)
{
    visited.resize(graph.size(), false);
    for (int i = 0; i < graph.size(); i++)
    {
        if (!visited.at(i))
        {
            DFS(graph, i);
        }
    }
}

void DFS(vector<vector<int>> &graph, int vertix)
{

    visited.at(vertix) = true;
    for (int i = 0; i < graph.at(vertix).size(); i++)
    {
        if (!visited.at(graph.at(vertix).at(i)))
        {
            DFS(graph, graph.at(vertix).at(i));
        }
    }

    finished.push(vertix);
}

int main()
{
    vector<vector<int>> graph = {{1, 3}, {2}, {}, {1, 4, 5}, {5}, {}};
    topological_sorting(graph);

    // Possible Order

    while (!finished.empty())
    {
        cout << finished.top() << " ";
        finished.pop();
    }
}