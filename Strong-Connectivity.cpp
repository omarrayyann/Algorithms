// Finding the number of connected components in an undirected graph

#include <iostream>
#include <vector>
using namespace std;

void DFS(vector<vector<int>> &graph, int vertix);

// Run-Time: O(M+N) where M is the number of edges and N is the number of vertices
// Input:
// 1- Graph as an adjacency list (Vector used for simplicity)
vector<bool> visited;

int number_of_connected_components(vector<vector<int>> graph)
{

    visited.resize(graph.size(), false);
    int components = 0;

    for (int i = 0; i < graph.size(); i++)
    {
        if (!visited.at(i))
        {
            DFS(graph, i);
            components++;
        }
    }
    return components;
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
}

// Example Run
int main()
{

    //  Sample Adjecency List
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
    cout << "Number of Components: " << number_of_connected_components(graph) << endl;
}
