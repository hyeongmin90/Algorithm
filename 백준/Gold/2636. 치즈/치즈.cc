#include <bits/stdc++.h>

using namespace std;

int board[101][101];
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
queue<pair<int, int>> q;
queue<pair<int, int>> qq;
bool vis[101][101];
int cheese, t, pre;

int main(){
    int n, m;
    cin >> n >> m;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin >> board[i][j];
            if(board[i][j] == 1) cheese++;
        }
    }       
    
    while(cheese > 0){
        t++;
        memset(vis, 0 , sizeof(vis));
        q.push({0, 0});
        while(!q.empty()){
            auto [x, y] = q.front();
            q.pop();
            for(int dir = 0; dir < 4; dir++){
                int nx = x + dx[dir];
                int ny = y + dy[dir];
                if(nx < 0 || nx >= n || ny < 0 || ny >= m)continue;
                if(vis[nx][ny]) continue;
                vis[nx][ny] = 1;
                if(board[nx][ny] == 1){
                    qq.push({nx, ny});
                    continue;
                }
                q.push({nx, ny});
            }
        }
        pre = cheese;
        cheese -= qq.size();
        while(!qq.empty()){
            auto [x, y] = qq.front();
            qq.pop();
            board[x][y] = 0;
        }
    }
    cout << t << '\n' << pre << '\n';
}