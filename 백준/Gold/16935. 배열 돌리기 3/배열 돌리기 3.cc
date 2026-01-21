#include <bits/stdc++.h>

using namespace std;

int board[101][101];
int n, m, r;

void func1(){
    int arr[101][101] = {};
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            arr[n - 1 - i][j] = board[i][j];
        }
    }
    memcpy(board, arr, sizeof(arr));
}

void func2(){
    int arr[101][101] = {};
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            arr[i][m - 1 - j] = board[i][j];
        }
    }
    memcpy(board, arr, sizeof(arr));
}

void func3(){
    int arr[101][101] = {};
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            arr[j][n - 1 - i] = board[i][j];
        }
    }
    int tmp = n;
    n = m;
    m = tmp;
    memcpy(board, arr, sizeof(arr));
}

void func4(){
    int arr[101][101] = {};
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            arr[m - 1 - j][i] = board[i][j];
        }
    }
    int tmp = n;
    n = m;
    m = tmp;
    memcpy(board, arr, sizeof(arr));
}

void func5(){
    int arr[101][101] = {};
    int x = n / 2, y = m / 2;
    
    for(int i = 0; i < x; i++){
        for(int j = 0; j < y; j++){
            arr[i][j] = board[i + x][j];
            arr[i + x][j] = board[i + x][j + y];
            arr[i][j + y] = board[i][j];
            arr[i + x][j + y] = board[i][j + y];
        }
    }
    memcpy(board, arr, sizeof(arr));
}

void func6(){
    int arr[101][101] = {};
    int x = n / 2, y = m / 2;
    
    for(int i = 0; i < x; i++){
        for(int j = 0; j < y; j++){
            arr[i][j] = board[i][j + y];
            arr[i + x][j] = board[i][j];
            arr[i][j + y] = board[i + x][j + y];
            arr[i + x][j + y] = board[i + x][j];
        }
    }
    memcpy(board, arr, sizeof(arr));
}


int main(){
    cin >> n >> m >> r;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin >> board[i][j];
        }
    }
    for(int i = 0; i < r; i++){
        int a;
        cin >> a;
        switch (a){
        case 1:
            func1();
            break;
        case 2:
            func2();
            break;
        case 3:
            func3();
            break;
        case 4:
            func4();
            break;
        case 5:
            func5();
            break;
        default:
            func6();
            break;
        }
    }

    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cout << board[i][j] << ' ';
        }
        cout << '\n';
    }
}