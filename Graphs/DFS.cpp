#include<iostream>
using namespace std;

class graph{
    private:
        int arr[8][8];
        int visited[8];
    public:
    graph(){
        int i, j;
        for (i = 0; i < 8;i++){
            for (j = 0; j < 8; j++)
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

        for (i = 0; i < 8; i++)
            visited[i] = false;
    }

    void dfs(int size, int i){
        int j;
        visited[i] = 1;
        cout << i + 1 << " ";

        for (j = 0; j < size; j++){
            if(visited[j] == 0 && arr[i][j] == 1)
                dfs(size, j);
        }
    }
};

int main(){
    graph g;
    g.dfs(8, 0);

    return 0;
}