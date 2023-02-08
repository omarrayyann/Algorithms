#include <iostream>
#include <vector>
#include <queue>

using namespace std;

// Run-Time: O(M+N) where M is the number of edges and N is the number of vertices
// Input:
// 1- Graph as an adjacency list (Vector used for simplicity)
// 2- Starting Vertix

vector<bool> visited;

void BFS(vector<vector<int>> &graph, int vertix)
{

    if (visited.empty())
    {
        visited.resize(graph.size(), false);
    }

    queue<int> queue;
    queue.push(vertix);
    visited.at(vertix) = true;
    
    while (!queue.empty())
    {

        int current_vertix = queue.front();
        queue.pop();
        
        for (int i = 0; i < graph.at(current_vertix).size(); i++)
        {

            if (!visited.at(graph.at(current_vertix).at(i)))
            {
                queue.push(graph.at(current_vertix).at(i));
                visited.at(graph.at(current_vertix).at(i)) = true;
            }
        }

        cout << "Finished the Discovery of Vertix (" << current_vertix << ")" << endl;
        
    }
}

// Example Run
int main()
{

    //  Sample Adjecency List
    vector<vector<int>> graph = {
        {1, 2},
        {0, 2, 3},
        {0, 1},
        {1}};

    // Sample Run
    BFS(graph, 0);
}
