#include <bits/stdc++.h>

using namespace std;

int n, m;
int board[51][51];
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
queue<pair<int, int>> q;
bool vis[51][51];

bool oob(int x, int y){
    return (x < 0 || x >= n || y < 0 || y >= m);
}

int bfs(int target_height){
    memset(vis, 0, sizeof(vis));
    int cnt = 0;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if (i == 0 || i == n - 1 || j == 0 || j == m - 1) continue;
            if (vis[i][j] || board[i][j] >= target_height) continue;
            q.push({i, j});
            vis[i][j] = 1;
            int tmp = 1;
            bool flag = true;
            while(!q.empty()){
                auto [x, y] = q.front();
                q.pop();
                for(int dir = 0; dir < 4; dir++){
                    int nx = x + dx[dir];
                    int ny = y + dy[dir];
                    if(oob(nx, ny)){
                        flag = false;
                        continue;
                    }
                    if(vis[nx][ny] || board[nx][ny] >= target_height) continue;
                    q.push({nx, ny});
                    vis[nx][ny] = 1;
                    tmp++;
                }
            }
            if(flag)
                cnt += tmp;
        }
    }
    return cnt;
}

int main(){
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> n >> m;
    for(int i = 0; i < n; i++){
        string line;
        cin >> line;
        for(int j = 0; j < m; j++){
            board[i][j] = line[j] - '0';
        }
    }

    int ans = 0;
    for(int i = 2; i <= 9; i++){
        ans += bfs(i);
    }
    cout << ans << '\n';
}