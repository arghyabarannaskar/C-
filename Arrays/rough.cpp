#include<iostream>
#include<vector>
using namespace std;

const int N = 1e3 + 10;
const int INF = 1e9 + 10;

vector<pair<int, int>> g[N];

void dijkstra(int source){
	
}

int main(){
	int n, m;
	for (int i = 0; i < m; i++){
		int x, y, wt;
		cin >> x >> y >> wt;
		g[x].push_back({y, wt});
	}

		return 0;
}