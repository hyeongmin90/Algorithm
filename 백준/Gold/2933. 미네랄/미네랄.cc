#include <bits/stdc++.h>

using namespace std;

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
char board[101][101];
int r, c;

void bfs(int h, bool right){
    for(int i = 0; i < c; i++){
        int row = (right ? c - 1 - i : i);
        if (board[h][row] == '.') continue;
        board[h][row] = '.';
        break;
    }

    int cluster[101][101] = {};
    queue<pair<int, int>> q;
    for(int i = 0; i < c; i++){
        if(board[0][i] == 'x'){
            q.push({0, i});
            cluster[0][i] = 1;
        }
    }

    while(!q.empty()){
        auto cur = q.front();
        int x = cur.first, y = cur.second;
        q.pop();
        for(int dir = 0; dir < 4; dir++){
            int nx = x + dx[dir];
            int ny = y + dy[dir];
            if(nx < 0 || nx >= r || ny < 0 || ny >= c) continue;
            if(board[nx][ny] == '.' || cluster[nx][ny] != 0) continue;
            q.push({nx, ny});
            cluster[nx][ny] = 1;
        }
    }

    vector<pair<int, int>> v;
    int height = 101;
    for(int i = 0; i < r; i++){
        for(int j = 0; j < c; j++){
            if(board[i][j] == '.' || cluster[i][j] == 1) continue;
            v.push_back({i, j});
            int cnt = 0;
            for(int k = i - 1; k >= 0; k--){
                if (board[k][j] == 'x' && cluster[k][j] == 1) break;
                cnt++;
            }
            height = min(height, cnt);
        }
    }
    for(auto c : v){
        int x = c.first, y = c.second;
        board[x][y] = '.';
        board[x - height][y] = 'x';
    }
}

int main(){
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> r >> c;
    for(int i = r - 1; i >= 0; i--){
        for(int j = 0; j < c; j++){
            cin >> board[i][j];
        }
    }
    int n;
    cin >> n;
    for(int i = 0; i < n; i++){
        int a;
        cin >> a;
        bfs(a - 1, i % 2 == 1);
    }    
    for(int i = r - 1; i >= 0; i--){
        for(int j = 0; j < c; j++){
            cout << board[i][j];
        }
        cout << '\n';
    }
}