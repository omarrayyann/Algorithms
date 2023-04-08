// Finding the number of connected components in an undirected graph

#include <iostream>
#include <vector>
using namespace std;

void DFS(vector<vector<int>> &graph, int vertix);

// Run-Time: O(M+N) where M is the number of edges and N is the number of vertices
// Input:
// 1- Graph as an adjacency list (Vector used for simplicity)
vector<bool> visited;

bool strong_connectivity(vector<vector<int>> graph)
{

    // Checking if the Normal Graph DFS visits all nodes

    DFS(graph, 0);

    for (int i = 0; i < visited.size(); i++)
    {
        if (!visited.at(i))
        {
            return false;
        }
    }

    // Checking if the Reversed Graph DFS visits all nodes

    // Forming the Reverse Graph
    vector<vector<int>> reverse_graph;

    reverse_graph.resize(graph.size());
    for (int i = 0; i < graph.size(); i++)
    {
        int from = i;
        for (auto to : graph.at(from))
        {
            reverse_graph.at(to).push_back(from);
        }
    }

    for (int i = 0; i < visited.size(); i++)
    {
        visited.at(i) = false;
    }
    DFS(reverse_graph, 0);
    for (int i = 0; i < visited.size(); i++)
    {
        if (!visited.at(i))
        {
            return false;
        }
    }

    return true;
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
        {1},
        {2},
        {3, 4},
        {0},
        {2}};
    // Visited Initilization
    visited.resize(graph.size(), false);

    // Sample Run
    cout << "Strongly Connected: " << strong_connectivity(graph) << endl;
}
