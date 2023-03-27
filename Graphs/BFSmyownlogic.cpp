#include<iostream>
#include<queue>
using namespace std;

int graph[6][6] = {
        0, 1, 1, 0, 0, 0,
        1, 0, 1, 0, 0, 1,
        1, 1, 0, 1, 1, 0,
        0, 0, 1, 0, 1, 1,
        0, 0, 1, 1, 0, 1,
        0, 1, 0, 1, 1, 0};

int visited[] = { 0, 0, 0, 0, 0, 0 };     
void BFS(int curr);     //In BFS we visit and mark visited first and then we enque the node for exploration...then we deque the node print it and then explore it ...we visit its childtren and mark them visited immediately and enque them in order
queue<int> q;

int main()
{
    int curr;
    cout << "Enter a starting address: ";
    cin >> curr;
    BFS(curr-1);
    return 0;
}

void BFS(int curr){
    visited[curr] = 1;   //node is visited so marked.. visited[curr] = 1
    q.push(curr);        // it is then pushed for exploration...   queue maintains the order in which they should get printed so insert in queue in Breadth First order
    while(!q.empty()){   //while q doesn't become empty
        int node = q.front();    //taking out one node from the queue
        q.pop();
        cout << node+1 << " ";     //printing it
        for (int j = 0; j < 6; j++){
            if(graph[node][j] == 1 && !visited[j]){   // if edge exists between this node and a node j and j is not visited then 
                q.push(j);    //push j
                visited[j] = 1;  //and mark it as visited otherwise double insertion problem will occur
            }
        }
    }
}