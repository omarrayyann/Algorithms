#include <iostream>
#include <vector>

using namespace std;

vector<bool> visited;
vector<int> finished;

void DFS(vector<vector<int>> graph, int s){

    if(visited[s]){
        return;
    }

    visited[s] = true;

    for(int i = 0; i<graph[s].size(); i++){
        if(!visited[graph[s][i]]){
            DFS(graph,graph[s][i]);
        }
    }

    finished.push_back(s);

}

vector<int> topological_sorting(vector<vector<int>> graph){

    visited.resize(graph.size(),false);

    for(int i = 0; i<graph.size(); i++){
        DFS(graph,i);
    }

    reverse(finished.begin(),finished.end());

    return finished;

}
 
int main()
{
    vector<vector<int>> graph = {{1, 3}, {2}, {}, {1, 4, 5}, {5}, {}};
    vector<int> my_order = topological_sorting(graph);
    vector<int> correct_order = {0,3,4,5,1,2};

    if(correct_order.size()!=my_order.size()){
        cout << "Wrong!" << endl;
        for(int i = 0; i<my_order.size(); i++){
            cout << my_order[i] << " ";
        }
        return 0;
    }

    for(int i = 0; i<my_order.size(); i++){
        if(correct_order[i]!=my_order[i]){
            cout << "Wrong!" << endl;
            for(int i = 0; i<my_order.size(); i++){
                cout << my_order[i] << " ";
            }
            return 0;
        }
    }

    cout << "Success!" << endl;
    
    
}
