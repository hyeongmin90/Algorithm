#include <bits/stdc++.h>

using namespace std;

int board[65][65];
int n, m;
bool vis[65][65];
queue<pair<int, int>> q;
int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};

void melt(){
    bool chk[65][65] = {};
    int w = (1 << n);
    for(int i = 0; i < w; i++){
        for(int j = 0; j < w; j++){
            int cnt = 0;
            for(int dir = 0; dir < 4; dir++){
                int nx = i + dx[dir];
                int ny = j + dy[dir];
                if(nx < 0 || nx >= w || ny < 0 || ny >= w) continue;
                if(board[nx][ny] > 0) cnt++;
            }
            if(cnt < 3 && board[i][j] > 0) chk[i][j] = 1;
        }
    }

    for(int i = 0; i < w; i++){
        for(int j = 0; j < w; j++){
            if(chk[i][j]) board[i][j]--;
        }
    }
}

void spin(int x, int y, int w){
    int tmp[65][65];
    for(int i = 0; i < w; i++){
        for(int j = 0; j < w; j++){
            tmp[j][w - 1 - i] = board[x + i][y + j];
        }
    }
    for(int i = 0; i < w; i++){
        for(int j = 0; j < w; j++){
            board[x + i][y + j] = tmp[i][j];
        }
    }
}

void func(int x, int y, int i, int d){
    if(d != i){
        int dd = d / 2;
        func(x, y, i, dd);
        func(x + dd, y, i, dd);
        func(x, y + dd, i, dd);
        func(x + dd, y + dd, i, dd);
    }
    else {
        spin(x, y, d);
    }
}

void bfs(){
    int cnt = 0;
    int max_ice = 0;
    int w = (1 << n);
    for(int i = 0; i < w; i++){
        for(int j = 0; j < w; j++){
            if(vis[i][j] || board[i][j] == 0) continue;
            int ice_cnt = 0;
            vis[i][j] = 1;
            q.push({i, j});
            while(!q.empty()){
                auto [x, y] = q.front();
                q.pop();
                if(board[x][y] != 0) cnt += board[x][y];
                ice_cnt++;
                for(int dir = 0; dir < 4; dir++){
                    int nx = x + dx[dir];
                    int ny = y + dy[dir];
                    if(nx < 0 || nx >= w || ny < 0 || ny >= w) continue;
                    if(!board[nx][ny] || vis[nx][ny]) continue;
                    vis[nx][ny] = 1;
                    q.push({nx, ny});
                }
            }
            max_ice = max(max_ice, ice_cnt);
        }
    }
    cout << cnt << '\n' << max_ice << '\n';
}

int main(){
    ios::sync_with_stdio(0), cout.tie(0), cin.tie(0);
    cin >> n >> m;
    for(int i = 0; i < (1 << n); i++){
        for(int j = 0; j < (1 << n); j++){
            cin >> board[i][j];
        }
    }
    for(int i = 0; i < m; i++){
        int l;
        cin >> l;
        func(0, 0, (1 << l), (1 << n));
        melt();
    }
    bfs();
}