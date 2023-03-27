#include<iostream>
#include<list>
#include<vector>
using namespace std;

class Graph{
    int V;
    vector<list<int>> adj;
    vector<bool> visited;

public:
    Graph(int V);
    void addedge(int u, int v);
    void DFS(int source);
};

Graph::Graph(int V){
    this->V = V;
    adj.resize(V);
    visited.resize(V, false);
}

void Graph::addedge(int u, int v){
    adj[u].push_back(v);
    adj[v].push_back(u);
}

void Graph::DFS(int source){
    visited[source] = true;
    cout << source << " ";
    for(auto adjacent: adj[source]){
        if(!visited[adjacent])
            DFS(adjacent);
    }
}

int main(){
    Graph g(6);
    g.addedge(0, 1);
    g.addedge(0, 2);
    g.addedge(0, 4);
    g.addedge(1, 2);
    g.addedge(1, 3);
    g.addedge(3, 5);
    g.addedge(4, 5);

    g.DFS(0);

    return 0;
}