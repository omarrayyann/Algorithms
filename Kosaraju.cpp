// Finding the number of strongly connected components in a directed graph

#include <iostream>
#include <vector>
#include <stack>
using namespace std;

void DFS(vector<vector<int>> &graph, int vertix);

vector<bool> visited;
stack<int> finished;
vector<vector<int>> components = {{}};

void kosaraju(vector<vector<int>> &graph)
{

    // 1. Reverse the Graph
    vector<vector<int>> reversed_graph;
    reversed_graph.resize(graph.size());
    for (int i = 0; i < graph.size(); i++)
    {
        for (int j = 0; j < graph.at(i).size(); j++)
        {
            reversed_graph.at(graph.at(i).at(j)).push_back(i);
        }
    }

    // 2. DFS on the Reversed Graph
    visited.clear();
    visited.resize(reversed_graph.size(), false);
    for (int i = 0; i < reversed_graph.size(); i++)
    {
        if (!visited.at(i))
        {
            DFS(reversed_graph, i);
        }
    }

    // 3. DFS on the Nodes with decreasing order of finishing time
    visited.clear();
    visited.resize(reversed_graph.size(), false);
    components.clear();
    stack<int> finished_temp = finished;
    while (!finished_temp.empty())
    {
        int currentNode = finished_temp.top();
        finished_temp.pop();
        if (!visited.at(currentNode))
        {
            components.push_back({});
            DFS(graph, currentNode);
        }
    }
}

void DFS(vector<vector<int>> &graph, int vertix)
{

    visited.at(vertix) = true;
    components.at(components.size() - 1).push_back(vertix);
    for (int i = 0; i < graph.at(vertix).size(); i++)
    {
        if (!visited.at(graph.at(vertix).at(i)))
        {
            DFS(graph, graph.at(vertix).at(i));
        }
    }

    finished.push(vertix);
}

// Example Run
int main()
{

    //  Sample Adjecency List
    vector<vector<int>> graph = {
        {2, 3},
        {0},
        {1},
        {4},
        {5},
        {3}};

    // Sample Run
    kosaraju(graph);
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
