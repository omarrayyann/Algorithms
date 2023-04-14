// Finding the number of strongly connected components in a directed graph

#include <iostream>
#include <vector>
using namespace std;

void DFS(vector<vector<int>> &graph, int vertix);

vector<bool> visited;
vector<int> finish_times;
vector<vector<int>> components = {};

void find_connected_components(vector<vector<int>> &graph)
{
    visited.resize(graph.size(), false);

    for (int i = 0; i < graph.size(); i++)
    {
        if (!visited.at(i))
        {
            components.push_back({});
            DFS(graph, i);
        }
    }
}

void DFS(vector<vector<int>> &graph, int vertix)
{

    if (!visited.empty())
    {
        visited.resize(graph.size(), false);
    }

    visited.at(vertix) = true;
    components.at(components.size() - 1).push_back(vertix);

    for (int i = 0; i < graph.at(vertix).size(); i++)
    {

        if (!visited.at(graph.at(vertix).at(i)))
        {
            DFS(graph, graph.at(vertix).at(i));
        }
    }
}

// Example Run
int main()
{

    //  Sample Adjecency Listx
    vector<vector<int>> graph = {
        {1, 2, 3},
        {0, 2, 3},
        {0, 1, 3},
        {0, 1, 2},
        {5},
        {4},
        {7, 8},
        {6, 8},
        {6, 7},
    };
    // Sample Run

    find_connected_components(graph);

    cout << "Number of Components: " << components.size() << endl;

    for (int i = 0; i < components.size(); i++)
    {
        cout << "Component " << i + 1 << ": " << endl;
        for (int j = 0; j < components.at(i).size(); j++)
        {
            cout << components.at(i).at(j) << " ";
        }
        cout << endl;
    }
}