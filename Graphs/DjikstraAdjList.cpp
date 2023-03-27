#include<iostream>
#include<set>
#include<vector>
using namespace std;
const int N = 1e3 + 10;
const int INF = 1e9 + 10;

vector<pair<int, int>> g[N];

void dijkstra(int source){
    vector<int> visited(N, 0);
    vector<int> distance(N, INF);

    set<pair<int, int>> st;
    st.insert({0, source});
    distance[source] = 0;

    while(st.size() > 0){
        auto node = *st.begin();
        int v = node.second;
        int v_dist = node.first;
        st.erase(st.begin());
        if(visited[v])
            continue;
        visited[v] = 1;
        for(auto adjacent: g[v]){
            int adjacent_v = adjacent.first;  //first is the node
            int wt = adjacent.second;            //second is the weigth
            if(distance[v] + wt < distance[adjacent_v]){
                distance[adjacent_v] = distance[v] + wt;
                st.insert({distance[adjacent_v], adjacent_v});
            }
        }
    }
}

int main(){
    int n, m;
    for (int i = 0; i < m; i++){

    }

    return 0;
}