#include<iostream>
using namespace std;
const int MAX = 3;

class matrix{
    private:
        int mat[MAX][MAX];
    public:
        matrix();
        void create();
        void display();
        void matadd(matrix &m1, matrix &m2);
        void matmul(matrix &m1, matrix &m2);
        void transpose(matrix &m1);
};

//initializes the matrix mat with 0
matrix::matrix(){
    for (int i = 0; i < MAX; i++){
        for (int j = 0; j < MAX; j++)
            mat[i][j] = 0;
    }
}

//creates matrix mat
void matrix::create(){
    int n;
    for (int i = 0; i < MAX;i++){
        for (int j = 0; j < MAX; j++){
            cout << endl
                 << "Enter the element: ";
            cin >> this->mat[i][j];
        }
    }
}

//displays the contents of matrix
void matrix::display(){
    for (int i = 0; i < MAX; i++){
        for (int j = 0; j < MAX; j++)
            cout << mat[i][j] << " ";
        cout << endl;
    }
}

//adds two matrices m1 and m2
void matrix::matadd(matrix &m1, matrix &m2){
    for (int i = 0; i< MAX; i++){
        for (int j = 0; j < MAX; j++){
            mat[i][j] = m1.mat[i][j] + m2.mat[i][j];
        }
    }
}

//multiplies two matrices m1 and m2
void matrix:: matmul(matrix &m1, matrix &m2){
    for (int k = 0; k < MAX; k++){
        for (int i = 0; i < MAX; i++){
            for (int j = 0; j < MAX; j++)
                mat[k][i] += m1.mat[k][j] * m2.mat[j][i];
        }
    }
}

//obtains transpose of matrix m1
void matrix::transpose(matrix &m1){
    for (int i = 0; i < MAX; i++){
        for (int j = 0; j < MAX; j++)
            mat[i][j] = m1.mat[j][i];
    }
}

int main(){
    matrix mat1;
    cout << endl
         << "Enter elements for first array: " << endl;
    mat1.create();

    matrix mat2;
    cout << endl
         << "Enter elements for second array: " << endl;
    mat2.create();

    cout << endl
         << "First Array: " << endl;
    mat1.display();
    cout << endl
         << "Second Array: " << endl;
    mat2.display();

    matrix mat3;
    mat3.matadd(mat1, mat2);
    cout << endl
         << "After Addition: " << endl;
    mat3.display();

    matrix m4;
    m4.matmul(mat1, mat2);
    cout << endl
         << "After multiplication: " << endl;
    m4.display();

    matrix m5;
    m5.transpose(mat1);
    cout << endl
         << "Transpose of first matrix: " << endl;
    m5.display();

    return 0;
}