// Finding the number of strongly connected components in a directed graph

#include <iostream>
#include <vector>
#include <stack>
using namespace std;

int maxFlow(vector<vector<int>>& graph){

    // reversing graph

    vector<vector<int>> rGraph;
    rGraph.resize(graph.size());

    

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

    int ans = maxFlow(graph);
    // Reverse Graph
}
