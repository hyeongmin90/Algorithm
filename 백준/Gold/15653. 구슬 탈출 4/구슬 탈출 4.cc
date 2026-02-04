#include <bits/stdc++.h>

using namespace std;

struct pos{
    int rx, ry, bx, by, depth;
};

int n, m;
char board[11][11];
bool vis[11][11][11][11];
queue<pos> q;
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

pair<int, int> move(int x, int y, int dir){
    while(board[x][y] != '#'){
        x += dx[dir];
        y += dy[dir];
        if(board[x][y] == 'O') return {x, y};
    }
    return {x - dx[dir], y - dy[dir]};
}

int bfs(){
    while(!q.empty()){
        auto [rx, ry, bx, by, depth] = q.front();
        q.pop();
        for(int dir = 0; dir < 4; dir++){
            auto red = move(rx, ry, dir);
            auto blue = move(bx, by, dir);
            if(board[red.first][red.second] == 'O'){
                if(red == blue) continue;
                return depth + 1;
            }
            if(board[blue.first][blue.second] == 'O') continue;
            if(red == blue){
                int rd = abs(rx - red.first) + abs(ry - red.second);
                int bd = abs(bx - blue.first) + abs(by - blue.second);
                if(rd > bd){
                    red.first -= dx[dir];
                    red.second -= dy[dir];
                }
                else {
                    blue.first -= dx[dir];
                    blue.second -= dy[dir];
                }
            }
            if(vis[red.first][red.second][blue.first][blue.second]) continue;
            vis[red.first][red.second][blue.first][blue.second] = 1;
            q.push({red.first, red.second, blue.first, blue.second, depth + 1});
        }
    }
    return -1;
}

int main(){
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    pos cur = {};
    cin >> n >> m;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin >> board[i][j];
            if(board[i][j] == 'B'){
                cur.bx = i;
                cur.by = j;
            }
            if(board[i][j] == 'R'){
                cur.rx = i;
                cur.ry = j;
            }
        }
    }
    q.push(cur);
    vis[cur.rx][cur.ry][cur.bx][cur.by] = 1;
    cout << bfs() << '\n';
}