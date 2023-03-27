#include<iostream>
using namespace std;

#define INF 9999
#define max 6
void djikstra(int G[max][max], int n, int startnode);

int main(){
    int G[max][max] = {
        0, 7, 9, 0, 0, 14, 
        7, 0, 10, 15, 0, 0, 
        9, 10, 0, 11, 0, 2, 
        0, 15, 11, 0, 6, 0,
        0, 0, 0, 6, 0, 9, 
        14, 0, 2, 0, 9, 0
    };

    int n = max;
    int u; // u is the starting node
    cout << "Enter the starting node: ";
    cin >> u;
    u--;
    djikstra(G, n, u); 

    return 0;
}

void djikstra(int G[max][max], int n, int startnode){
    int cost[max][max], distance[max], pred[max];     //distance array will store the distance of each node from starting node. After the end of the program pred[max] will store the predecessor of each node in the shortest path.
    int visited[max], count, mindistance, nextnode, i, j;
    for (i = 0; i < n; i++){           //loops for creating cost matrix from adjacency matrix
        for (j = 0; j < n; j++){
            if(G[i][j] == 0)           //if direct edge doesn't exist
                cost[i][j] = INF;      //distance is infinity
            else 
                cost[i][j] = G[i][j];  //else the weight of the edge is assigned in cost matrix
        }
    }

    for (i = 0; i < n; i++){
        distance[i] = cost[startnode][i]; //distance from starting node to (ith) node is stored in the distance array
        pred[i] = startnode;              // predecessor of each node initially is startnode
        visited[i] = 0; //marking all nodes as unvisited
    }

    distance[startnode] = 0;
    visited[startnode] = 1;
    count = 1;

    while(count<n-1){       //well explained in code visualization notebook
        mindistance = INF;
        for (i = 0; i < n; i++){   //loop to find the minimum distance among unvisited nodes
            if(!visited[i] && distance[i]<mindistance){
                mindistance = distance[i];
                nextnode = i;
            }
        }
        visited[nextnode] = 1; // now we are choosing the minimum among all the distances and marking it as visited

        for (i = 0; i < n; i++){
            if(!visited[i]){    //loop to relax the distance of unvisited nodes from the current node in the shortest path
                if(mindistance + cost[nextnode][i] < distance[i]){
                    distance[i] = mindistance + cost[nextnode][i];  //
                    pred[i] = nextnode; // if this path is the shortest then nextnode is the predecessor of ith node in this path
                }
            }
        }
         count++;
    }

    for (i = 0; i < n; i++){
        cout << "\nDistance of node " << i+1 << "= " << distance[i];
        cout << "\nPath = " << i+1;
        j = i;
        do{
            j = pred[j];
            cout << "<-" << j+1;
        } while (j != startnode);
    }
}