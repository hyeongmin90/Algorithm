#include <bits/stdc++.h>

using namespace std;

struct p
{
    int x;
    int y;
    int cnt;
    int key;
};

string board[51];
bool vis[51][51][65];
queue<p> q;
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

int main(){
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n, m;
    cin >> n >> m;
    for(int i = 0; i < n; i++){
        cin >> board[i];
        for(int j = 0; j < m; j++){
            if(board[i][j] == '0'){
                p cur = {i, j, 0, 0};
                q.push(cur);
            }
        }
    }
    
    while(!q.empty()){
        p cur = q.front();
        q.pop();
        for(int dir = 0; dir < 4; dir++){
            int nx = cur.x + dx[dir];
            int ny = cur.y + dy[dir];
            int key = cur.key;
            if(nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
            if(board[nx][ny] == '#') continue;
            if(board[nx][ny] >= 'A' && board[nx][ny] <= 'F'){
                int k = board[nx][ny] - 'A';
                if(!(key & (1 << k))) continue;
            }

            if(board[nx][ny] == '1'){
                cout << cur.cnt + 1 << '\n';
                return 0;
            }

            if(board[nx][ny] >= 'a' && board[nx][ny] <= 'f'){
                int k = board[nx][ny] - 'a';
                key |= (1 << k);
            }
            if(vis[nx][ny][key]) continue;

            vis[nx][ny][key] = 1;
            q.push({nx, ny, cur.cnt + 1, key});
        }
    }
    cout << -1 << '\n';
}