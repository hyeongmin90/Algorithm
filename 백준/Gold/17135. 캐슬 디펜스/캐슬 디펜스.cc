#include <bits/stdc++.h>

using namespace std;

int board[16][16];
int tmp[16][16];
bool vis[16][16];
int dx[3] = {0, -1, 0};
int dy[3] = {-1, 0, 1};
int n, m, d, idx, ans;
int dd[16][16];
queue<pair<int, int>> qq;

int bfs(int i, int j){
    queue<pair<int, int>> q;
    memset(dd, -1, sizeof(dd));
    dd[i][j] = 0;
    q.push({i, j});
    while(!q.empty()){
        auto [x, y] = q.front();
        q.pop();
        for(int dir = 0; dir < 3; dir++){
            int nx = x + dx[dir];
            int ny = y + dy[dir];
            if(nx < 0 || nx >= idx || ny < 0 || ny >= m)continue;
            if(dd[nx][ny] != -1)continue;
            if(tmp[nx][ny] == 1){
                if(!vis[nx][ny]){
                    vis[nx][ny] = true;
                    qq.push({nx, ny});
                    return 1;
                }
                return 0;
            }
            dd[nx][ny] = dd[x][y] + 1;
            if(dd[nx][ny] < d) q.push({nx, ny});
        }
    }
    return 0;
}

int main(){
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> n >> m >> d;
    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
            cin >> board[i][j];
    
    vector<int> v(m);
    fill(v.end() - 3, v.end(), 1);
    do{
        for(int i = 0; i < n; i++)
            for(int j = 0; j < m; j++)
                tmp[i][j] = board[i][j];
        
        idx = n;
        int cnt = 0;
        memset(vis, false, sizeof(vis));
        while(idx){
            for(int j = 0; j < m; j++){
                if(!v[j])continue;
                cnt += bfs(idx, j);
            }
            while(!qq.empty()){
                tmp[qq.front().first][qq.front().second] = 0;
                qq.pop();
            }
            ans = max(ans, cnt);
            idx--;
        }
    }while(next_permutation(v.begin(), v.end()));

    cout << ans << '\n';
}