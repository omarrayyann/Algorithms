#include <iostream>
#include <vector>
#include <climits>
#include <cmath>
#include <unordered_map>
#include <unordered_set>
#include <queue>

using namespace std;

// {From, To}, Weight
typedef pair<vector<int>, int> edge;
 
struct edgeSorting
{
    constexpr bool operator()(
        pair<vector<int>, int> const &a,
        pair<vector<int>, int> const &b)
        const noexcept
    {
        return a.second > b.second;
    }
};
 
class DisjointSet
{
    unordered_map<int, int> parent;
    unordered_map<int, int> rank;
 
public:
    void makeSet(int setSize)
    {
 
        for (int i = 0; i < setSize; i++)
        {
            parent[i] = i;
            rank[i] = 0;
        }
    }
    int find(int node)
    {
        if (parent[node] == node)
        {
            return node;
        }
        else
        {
            return find(parent[node]);
        }
    }
 
    void unionSets(int nodeA, int nodeB)
    {
 
        int aParent = find(nodeA);
        int bParent = find(nodeB);
 
        int aRank = rank[nodeA];
        int bRank = rank[nodeB];
 
        if (aRank == bRank)
        {
            parent[bParent] = aParent;
            rank[aParent] += 1;
        }
        else if (aRank > bRank)
        {
            parent[bParent] = aParent;
        }
        else
        {
            parent[aParent] = bParent;
        }
    }
};
 
vector<vector<int>> minimumSpanningTree(vector<vector<int>> graph)
{
 
    // Edges in MST
    vector<vector<int>> MST_Edges;
 
    // Sorted Edges
    priority_queue<edge, vector<edge>, edgeSorting> edgesPQ;
    // Extracting the edges in the graph
    for (int from = 0; from < graph.size(); from++)
    {
        for (int to = 0; to < graph.at(from).size(); to++)
        {
            int cost = graph.at(from).at(to);
            if (cost)
            {
                vector<int> edgeNodes = {from, to};
                edgesPQ.push(make_pair(edgeNodes, cost));
            }
        }
    }
 
    // Making the disjointSet Structure
    DisjointSet disjointSet;
    disjointSet.makeSet(graph.size());
    // Looping through the edges from lightest to heaviest
    while (!edgesPQ.empty())
    {
        vector<int> edgeNodes = edgesPQ.top().first;
        edgesPQ.pop();
        int from = edgeNodes.at(0);
        int to = edgeNodes.at(1);
 
        // If they happen to be in different trees
        if (disjointSet.find(from) != disjointSet.find(to))
        {
            disjointSet.unionSets(from, to);
            MST_Edges.push_back(edgeNodes);
        }
    }
 
    return MST_Edges;
}
 

int main()
{
    // Adjacency Matrix
    vector<vector<int>> graph = 
     {  { 0, 2, 0, 6, 0 },
        { 2, 0, 3, 8, 5 },
        { 0, 3, 0, 0, 7 },
        { 6, 8, 0, 0, 9 },
        { 0, 5, 7, 9, 0 } };

    vector<vector<int>> MST_Edges = minimumSpanningTree(graph);
    vector<vector<int>> answer = {
        {0,1},
        {1,2},
        {1,4},
        {0,3},
    };

    if(MST_Edges.size()!=answer.size()){
        cout << "Wrong!" << endl;
        for(int i = 0; i<MST_Edges.size(); i++){
            cout << "(" <<  MST_Edges[i][0] << ", " << MST_Edges[i][1] << ")" << endl;;
        }
        return 0;
    }

    for(int i = 0; i<MST_Edges.size(); i++){
        if(answer[i][0]!=MST_Edges[i][0] || answer[i][1]!=MST_Edges[i][1]){
            cout << "Wrong!" << endl;
            for(int i = 0; i<MST_Edges.size(); i++){
                cout << "(" <<  MST_Edges[i][0] << ", " << MST_Edges[i][1] << ")" << endl;;
            }
            return 0;
        }
    }

    cout << "Success!" << endl;
    

}
