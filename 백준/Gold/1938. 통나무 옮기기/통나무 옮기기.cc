#include <bits/stdc++.h>

using namespace std;

struct l {
    int x, y, dir;
};

int n;
char board[52][52];
int dist[52][52][2];
int dx[8] = {-1, 1, 0, 0, -1, -1, 1, 1};
int dy[8] = {0, 0, -1, 1, -1, 1, -1, 1};
queue<l> q;
l goal;

bool oob(int nx, int ny, int d){
    if(nx < 1 || nx > n || ny < 1 || ny > n || board[nx][ny] == '1') return true;
    if(d == 1){
        if(nx < 2 || nx > n - 1) return true;
        if(board[nx + 1][ny] == '1' || board[nx - 1][ny] == '1') return true;
    }
    else{
        if(ny < 2 || ny > n - 1) return true;
        if(board[nx][ny + 1] == '1' || board[nx][ny - 1] == '1') return true;
    }
    return false;
}

bool can_spin(int x, int y){
    for(int dir = 0; dir < 8; dir++){
        int nx = x + dx[dir];
        int ny = y + dy[dir];
        if(nx < 1 || nx > n || ny < 1 || ny > n || board[nx][ny] == '1') return false;
    }
    return true;
}

void bfs(){
    while(!q.empty()){
        auto cur = q.front();
        q.pop();
        int x = cur.x, y = cur.y, d = cur.dir;
        for(int dir = 0; dir < 4; dir++){
            int nx = x + dx[dir];
            int ny = y + dy[dir];
            if(oob(nx, ny, d)) continue;
            if(dist[nx][ny][d] != 0) continue;
            dist[nx][ny][d] = dist[x][y][d] + 1;
            q.push({nx, ny, d});
        }
        if(dist[x][y][(d + 1) % 2] == 0 && can_spin(x, y)){
            dist[x][y][(d + 1) % 2] = dist[x][y][d] + 1;
            q.push({x, y, (d + 1) % 2});
        }
    }
}

int main(){
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> n;
    for(int i = 1; i <= n; i++){
        string str;
        cin >> str;
        for(int j = 1; j <= n; j++){
            board[i][j] = str[j - 1];
        }
    }

    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            if(board[i][j] == 'B'){
                if(board[i + 1][j] == 'B' && board[i - 1][j] == 'B')
                    q.push({i, j, 1});

                if(board[i][j + 1] == 'B' && board[i][j - 1] == 'B')
                    q.push({i, j, 0});  
            }
            if(board[i][j] == 'E'){
                if(board[i + 1][j] == 'E' && board[i - 1][j] == 'E')
                    goal = {i, j, 1};

                if(board[i][j + 1] == 'E' && board[i][j - 1] == 'E')
                    goal = {i, j, 0};
            }
        }
    }
    bfs();
    cout << dist[goal.x][goal.y][goal.dir] << '\n';
}