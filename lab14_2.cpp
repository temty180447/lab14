#include<iostream>
using namespace std;

const int N = 5;

void inputMatrix(double [][N]);

void findLocalMax(const double [][N], bool [][N]);

void showMatrix(const bool [][N]);

int main(){
	double A[N][N]; 
	bool B[N][N]; 
	cout << "Input the matrix.....\n";
	inputMatrix(A);
	findLocalMax(A,B);
	cout << "Result is \n";
	showMatrix(B);
	return 0;
}

void inputMatrix(double matrix[][N]) {
    for (int i = 0; i < N; i++) {
        cout << "Row " << i+1 << ": ";
        for (int j = 0; j < N; j++) {
            cin >> matrix[i][j];
        }
    }
}

void findLocalMax(const double matrix[][N], bool result[][N]) {
    for (int i = 1; i < N - 1; i++) {
        for (int j = 1; j < N - 1; j++) {
            if (matrix[i][j] >= matrix[i - 1][j] &&
                matrix[i][j] >= matrix[i + 1][j] &&
                matrix[i][j] >= matrix[i][j - 1] &&
                matrix[i][j] >= matrix[i][j + 1]) {
                
                result[i][j] = true;
                
            } else {
            
                result[i][j] = false;
                
            }
        }
    }
    for(int k = 0; k < N; k++){
        result[0][k] = false;
        result[N-1][k] = false;
    }
    for(int m = 0; m < N; m++){
        result[m][0] = false;
        result[m][N-1] = false;
    }
}

void showMatrix(const bool result[][N]){
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cout << result[i][j] << " ";
        }
        cout << endl;
    }
}