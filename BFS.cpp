//Breadth First Search
#include<bits/stdc++.h>
using namespace std;
void addEdge(vector<int> adj[],int u,int v){
    adj[u].push_back(v);
    //adj[v].push_back(u);
}
void BFS(vector<int> adj[],int vertices,int source){
    bool Visited[vertices]={false};
    queue<int> q;
    Visited[source]=true;
    q.push(source);
    while(!q.empty()){
        int s=q.front();
        cout<<s<<" ";
        q.pop();
        for(int i=0;i<adj[s].size();i++){
            if(!Visited[adj[s][i]]){
                Visited[adj[s][i]]=true;
                q.push(adj[s][i]);
            }
        }
    }
}
int main(){
    int vertices=4;
    vector<int> adj_list[vertices];
    addEdge(adj_list,0,1);
    addEdge(adj_list,0,2);
    addEdge(adj_list,1,2);
    addEdge(adj_list,2,0);
    addEdge(adj_list,2,3);
    addEdge(adj_list,3,3);
    BFS(adj_list,vertices,2);
    return 0;
}