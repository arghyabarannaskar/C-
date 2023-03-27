#include<iostream>
#include<list>
#include<vector>
using namespace std;

class Graph{
    int V;
    vector<list<int>> adj;

    public:
        Graph(int V);    //V is the no. of vertices
        void addedge(int v, int w);
        void BFS(int s);
};

Graph::Graph(int V){
    this->V = V;
    adj.resize(V);
}

void Graph::addedge(int v, int w){
    adj[v].push_back(w);  //v is the index of the node we are at and w is its adjacent node
} //adj[v] is a list and we are pushing w to a list

//for undirected graph we also have to push_back adj[w].push_back(v) because it goes both ways

void Graph::BFS(int s){
    vector<bool> visited;   //visited vector
    visited.resize(V, false);  //resizing the vector to size of V and filling with false

    list<int> q;
    visited[s] = true;
    q.push_back(s);
    while(!q.empty()){
        s = q.front();
        cout << s << " ";
        q.pop_front();
        for(auto adjacent: adj[s]){
            if(!visited[adjacent]){
                visited[adjacent] = true;
                q.push_back(adjacent);
            }
        }
    }
}

int main(){
    Graph g(4);
    g.addedge(0, 2);
    g.addedge(2, 0);
    g.addedge(2, 3);
    g.addedge(3, 3);
    g.addedge(1, 2);
    g.addedge(0, 1);

    g.BFS(1);

    return 0;
}