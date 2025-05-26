#include <bits/stdc++.h>

using namespace std;

int board[201][201];
queue<pair<int, int>> q;
int t;
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
int n, m, k;

void input(){
    cin >> n >> m >> k;
    for(int i = 0; i < n; i++){
        string rows;
        cin >> rows;
        for(int j = 0; j < m; j++){
            if(rows[j] == 'O') board[i][j] = 3;
        }
    }
}

void func1(){
    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
            if(board[i][j] == 0) board[i][j] = 3;
}

void func2(){
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(board[i][j] == 0) continue;
            if(board[i][j] == 1){
                q.push({i, j});
                for(int dir = 0; dir < 4; dir++){
                    int nx = i + dx[dir];
                    int ny = j + dy[dir];
                    if(nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
                    q.push({nx, ny});
                }
            }
            else board[i][j]--;
        }
    }
}

void func3(){
    while(!q.empty()){
        auto [x, y] = q.front(); q.pop();
        board[x][y] = 0;
    }
}

void output(){
    for(int i = 0; i < n; i++){
       for(int j = 0; j < m; j++){
            cout << (board[i][j] == 0 ? '.' : 'O');
       }
       cout << '\n';
    }
}

int main(){
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    input();
    while(t++ < k){
        func2();
        if(t % 2 == 0) func1();
        func3();
    }
    output();
}