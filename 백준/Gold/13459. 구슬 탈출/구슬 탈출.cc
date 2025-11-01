#include <bits/stdc++.h>

using namespace std;

struct p {
    int rx, ry, bx, by, cnt;
};

char board[11][11];
queue<p> q;
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
bool vis[11][11][11][11];
int n, m;

pair<int, int> func(int x, int y, int dir){
    while(1){
        int nx = x + dx[dir];
        int ny = y + dy[dir];
        if(board[nx][ny] == '#') return {x, y};
        if(board[nx][ny] == 'O') return {nx, ny};
        x = nx;
        y = ny;
    }
    return {-1, -1};
}

int bfs(){
    while(!q.empty()){
        auto [rx, ry, bx, by, cnt] = q.front();
        q.pop();
        if(cnt >= 10) continue;
        for(int dir = 0; dir < 4; dir++){
            auto [nrx, nry] = func(rx, ry, dir);
            auto [nbx, nby] = func(bx, by, dir);
            if(board[nbx][nby] == 'O') continue;
            if(board[nrx][nry] == 'O' && cnt + 1 <= 10) return 1;

            if(nrx == nbx && nry == nby){
                if(dir % 2 == 0){ //x 값 움직임
                    int drx = abs(nrx - rx);
                    int dbx = abs(nbx - bx);
                    if(drx > dbx) nrx -= dx[dir];
                    else nbx -= dx[dir];
                }
                else{
                    int dry = abs(nry - ry);
                    int dby = abs(nby - by);
                    if(dry > dby) nry -= dy[dir];
                    else nby -= dy[dir];
                }    
            }

            if(vis[nrx][nry][nbx][nby]) continue;
            vis[nrx][nry][nbx][nby] = 1;
            q.push({nrx, nry, nbx, nby, cnt + 1});
        }
    }
    return 0;
}

int main(){
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> n >> m;
    p temp;
    temp.cnt = 0;
    for(int i = 0; i < n; i++){
        string a;
        cin >> a;
        for(int j = 0; j < m; j++){
            board[i][j] = a[j];
            if(a[j] == 'R'){
                temp.rx = i;
                temp.ry = j;
            }
            if(a[j] == 'B'){
                temp.bx = i;
                temp.by = j;
            }
        }
    }
    vis[temp.rx][temp.ry][temp.bx][temp.by] = 1;
    q.push(temp);
    cout << bfs() << '\n';
}