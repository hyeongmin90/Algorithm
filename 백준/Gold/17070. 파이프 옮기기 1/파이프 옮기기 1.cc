#include <bits/stdc++.h>

using namespace std;

int board[16][16];
int n, ans;

int dx[3] = {0, 1, 1};
int dy[3] = {1, 1, 0};

bool check(int x, int y, int dir){
    if(dir == 1) return board[x][y] != 1 && board[x - 1][y] != 1 && board[x][y - 1] != 1;
    else return board[x][y] != 1;
}

void dfs(int x, int y, int dir){
    if(x == n - 1 && y == n - 1){
        ans++;
        return;
    }
    for(int i = 0; i < 3; i++){
        if((dir == 0 && i == 2) || (dir == 2 && i == 0)) continue;
        int nx = x + dx[i];
        int ny = y + dy[i];
        if(nx >= n || ny >= n) continue;
        if(!check(nx, ny, i)) continue;
        dfs(nx, ny, i);
    }
}

int main(){
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> n;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cin >> board[i][j];
        }
    }
    dfs(0, 1, 0);
    cout << ans << '\n';

}