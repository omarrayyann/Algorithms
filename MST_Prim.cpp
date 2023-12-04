#include <iostream>
#include <vector>
#include <climits>
#include <cmath>
#include <unordered_map>
#include <unordered_set>
#include <queue>

using namespace std;

vector<vector<int>> minimumSpanningTree(vector<vector<int>>& graph){
priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>> pq;
unordered_set<int> set;
vector<vector<int>> answer;
int lastNode = 0;
int count = 1;
while(count<graph.size()){
    for(int i = 0; i<graph[lastNode].size(); i++){
        if(graph[lastNode][i]!=0){
            pq.push(make_pair(graph[lastNode][i],make_pair(lastNode,i)));
        }
    }
    bool done = false;
    while(!done){
        pair<int,pair<int,int>> n = pq.top();
        if(set.find(n.second.first)!=set.end() && set.find(n.second.second)!=set.end()){
            pq.pop();
            continue;
        }
        answer.push_back({pq.top().second.first,pq.top().second.second});
        set.insert(pq.top().second.first);
        set.insert(pq.top().second.second);
        done = true;
        if(lastNode==pq.top().second.first){
            lastNode = pq.top().second.second;
        } else {
            lastNode = pq.top().second.first;
        }
        pq.pop();
        count++;
    }

}
return answer;
