#include<iostream>
using namespace std;

const int MAX = 10;

class queue{
    private:
        int arr[MAX], front, rear;

    public:
    queue(){
        front = rear = -1;
    }

    void enqueue(int item){
        if(rear == MAX-1){
            cout << "Queue is full!" << endl;
            return;
        }

        rear++;
        arr[rear] = item;
        if(front == -1)
            front = 0;
    }

    int dequeue(){
        int data;

        if(front == -1){
            cout << "Queue is empty!" << endl;
            return -1;
        }

        data = arr[front];
        if(front == rear)
            front = rear = -1;
        else
            front++;
        return data;
    }

    bool isempty(){
        if(front == -1 && rear == -1)
            return true;
        else
            return false;
    }
};

class graph{
    private:
        int arr[8][8];
        int visited[8];
    public:
    graph(){
        int i, j;

        for(i = 0; i<8; i++){
            for (j = 0; j<8; j++)
                arr[i][j] = 0;
        }

        arr[0][1] = arr[1][0] = 1;
        arr[0][2] = arr[2][0] = 1;
        arr[1][3] = arr[3][1] = 1;
        arr[1][4] = arr[4][1] = 1;
        arr[2][5] = arr[5][2] = 1;
        arr[2][6] = arr[6][2] = 1;
        arr[3][7] = arr[7][3] = 1;
        arr[4][7] = arr[7][4] = 1;
        arr[5][7] = arr[7][5] = 1;
        arr[6][7] = arr[7][6] = 1;

        for(i = 0; i<8; i++)
            visited[i] = false;
    }

    void bfs(int sz){
        queue q;
        int i, j;

        q.enqueue(0);
        while(!q.isempty()){
            i = q.dequeue();
            if(visited[i] == 0){
                visited[i] = true;
            cout << i + 1 << " ";
            for (j = 0; j < sz; j++){
                if(visited[j] == false && arr[i][j] == 1)
                    q.enqueue(j);
            }
            }
            
        }
    }
};

int main(){
    graph g;
    g.bfs(8);

    return 0;
}