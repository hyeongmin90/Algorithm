#include<bits/stdc++.h>

using namespace std;

int board[501][501];
int dist[501][501];
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
int n, ans;

int dfs(int x, int y){
    if(dist[x][y] != 0) return dist[x][y];
    dist[x][y] = 1;
    for(int dir = 0; dir < 4; dir++){
        int nx = x + dx[dir];
        int ny = y + dy[dir];
        if(nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
        if(board[nx][ny] <= board[x][y]) continue;
        dist[x][y] = max(dist[x][y], dfs(nx, ny) + 1);
    }
    return dist[x][y];
}

int main(){
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> n;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cin >> board[i][j];
        }
    }
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            ans = max(ans, dfs(i, j));
        }
    }
    cout << ans << '\n';
}