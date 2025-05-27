#include <bits/stdc++.h>

using namespace std;

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, -1, 0, 1};
int board[120][120];
int x, y, X, Y;

int main(){
    int n; 
    string str;
    cin >> n >> str;
    pair<int, int> cur = {60, 60};
    board[60][60] = 1;
    int dir = 0;
    x = 60;
    X = 60;
    y = 60;
    Y = 60;
    for(int i = 0; i < n; i++){
        if(str[i] == 'F'){
            auto [nx, ny] = cur;
            nx += dx[dir];
            ny += dy[dir];
            board[nx][ny] = 1;
            cur = {nx, ny};
            x = min(x, nx); X = max(X, nx);
            y = min(y, ny); Y = max(Y, ny);
        }
        else if(str[i] == 'R'){
            dir = (dir + 1) % 4;
        }
        else{
            dir = (dir - 1 < 0 ? 3 : dir - 1);
        }
    }
    for(int i = x; i <= X; i++){
        for(int j = y; j <= Y; j++){
            cout << (board[i][j] == 1 ? "." : "#");
        }
        cout << '\n';
    }
}