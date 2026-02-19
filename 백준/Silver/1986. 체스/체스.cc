#include <bits/stdc++.h>

using namespace std;

int board[1001][1001];
bool danger[1001][1001];
int n, m;

bool oob(int x, int y){
    return x < 1 || x > n || y < 1 || y > m;
}

void queen(int x, int y){
    int dx[8] = {-1, -1, 0, 1, 1, 1, 0, -1};
    int dy[8] = {0, 1, 1, 1, 0, -1, -1, -1};
    for(int dir = 0; dir < 8; dir++){
        int nx = x, ny = y;
        while(1){
            nx += dx[dir];
            ny += dy[dir];
            if(oob(nx, ny) || board[nx][ny] != 0) break;
            danger[nx][ny] = 1;
        }
    }
}

void knight(int x, int y){
    int dx[8] = {-2, -1, 1, 2, 2, 1, -1, -2};
    int dy[8] = {1, 2, 2, 1, -1, -2, -2, -1};
    for(int dir = 0; dir < 8; dir++){
        int nx = x + dx[dir];
        int ny = y + dy[dir];
        if(oob(nx, ny)) continue;
        danger[nx][ny] = 1;
    }
}

int main(){
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> n >> m;
    for(int i = 0; i < 3; i++){
        int p; 
        cin >> p;
        for(int j = 0; j < p; j++){
            int x, y;
            cin >> x >> y;
            board[x][y] = i + 1;
            danger[x][y] = 1;
        }
    }

    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            if(board[i][j] == 1) queen(i, j);
            else if (board[i][j] == 2) knight(i, j);
        }
    }
    int ans = 0;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            if(!danger[i][j]) ans++;
        }
    }
    cout << ans << '\n';
}