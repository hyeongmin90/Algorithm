#include <bits/stdc++.h>

using namespace std;

int n, m, cnt;
int board[101][101];
queue<pair<int, int>> q;
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

bool func(){
    bool vis[101][101] = {};
    int air[101][101] = {};
    queue<pair<int, int>> melt;
    q.push({0, 0});
    vis[0][0] = 1;
    while(!q.empty()){
        auto [x, y] = q.front();
        q.pop();
        for(int dir = 0; dir < 4; dir++){
            int nx = x + dx[dir];
            int ny = y + dy[dir];
            if(nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
            if(vis[nx][ny]) continue;
            if(board[nx][ny] == 1){
                if(++air[nx][ny] >= 2) melt.push({nx, ny});
                continue;
            }
            vis[nx][ny] = 1;
            q.push({nx, ny});
        }
    }
    if(melt.empty()) return false;
    while(!melt.empty()){
        auto [x, y] = melt.front();
        melt.pop();
        board[x][y] = 0;
    }
    cnt++;
    return true;
}

int main(){
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> n >> m;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin >> board[i][j];
        }
    }
    while(func()) {}
    cout << cnt << '\n';
}

