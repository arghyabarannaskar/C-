#include<iostream>
using namespace std;

int graph[6][6] = {
        0, 1, 1, 0, 0, 0,
        1, 0, 1, 0, 0, 1,
        1, 1, 0, 1, 1, 0,
        0, 0, 1, 0, 1, 1,
        0, 0, 1, 1, 0, 1,
        0, 1, 0, 1, 1, 0};

int visited[] = { 0, 0, 0, 0, 0, 0 };
void DFS(int i);

int main()
{
    DFS(0); //passing the index of the starting node
    return 0;
}

void DFS(int i){
    cout << i + 1 << " ";     // it is visited and printed
    visited[i] = 1;            //marked as visited
    for (int j = 0; j < 6; j++){    
        if(graph[i][j] == 1 && !visited[j])    //we are at i at this moment. If edge exists between i and j and j is not visited then visit j 
            DFS(j);
    }
}