// Finding the number of strongly connected components in a directed graph

#include <iostream>
#include <vector>
using namespace std;

void DFS(vector<vector<int>> &graph, int vertix);

vector<bool> visited;
vector<int> finish_times;

// Run-Time: O(M+N) where M is the number of edges and N is the number of vertices
// Input:
// 1- Graph as an adjacency list (Vector used for simplicity)
int number_of_strongly_connected_components(vector<vector<int>> &graph)
{

    // 1. Reverse the Graph
    vector<vector<int>> reversed_graph;
    for (int i = 0; i < graph.size(); i++)
    {
        for (int i = 0; i < graph.size(); i++)
        {
            reversed_graph.at(i).at(j) = graph.at(j).at(i);
        }
    }
}

void DFS(vector<vector<int>> &graph, int vertix)
{

    if(!visited.empty()){
        visited.resize(graph.size(), false);
    }

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
