#include <bits/stdc++.h>

using namespace std;

struct triple{
    int x, y, d;
};

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
int r, c;
char board[26][26];
int pipe_route[7][4] = {
    {0, -1, 2, -1},
    {-1, 1, -1, 3},
    {0, 1, 2, 3},
    {-1, -1, 1, 0},
    {1, -1, -1, 2},
    {3, 2, -1, -1},
    {-1, 0, 3, -1},
};
map<char, int> pipe_n = {{'|', 0}, {'-', 1}, {'+', 2}, {'1', 3}, {'2', 4}, {'3', 5}, {'4', 6}};
char pipes[7] = {'|', '-', '+', '1', '2', '3', '4'};
bool vis[26][26];

int find_dir(int x, int y){
    for(int dir = 0; dir < 4; dir++){
        int nx = x + dx[dir];
        int ny = y + dy[dir];
        if(nx < 0 || nx >= r || ny < 0 || ny >= c) continue;
        if(board[nx][ny] == '.' || isalpha(board[nx][ny])) continue;
        return dir;
    }
    return -1;
}

pair<int, int> find_blank(int x, int y, int dir){
    queue<triple> q;
    q.push({x, y, dir});
    while(!q.empty()){
        auto [x_, y_, d] = q.front();
        q.pop();
        int nx = x_ + dx[d];
        int ny = y_ + dy[d];
        if(nx < 0 || nx >= r || ny < 0 || ny >= c) continue;
        char pipe = board[nx][ny];
        if(pipe == '.') return {nx, ny};
        int n = pipe_n[pipe];
        int nd = pipe_route[n][d];
        if(nd != -1) q.push({nx, ny, nd});
    }
    return {-1, -1};
}

int count_vis_pipe(){
    int cnt = 0;
    for(int i = 0; i < r; i++){
        for(int j = 0; j < c; j++){
            if(vis[i][j] && board[i][j] != '.' && !isalpha(board[i][j])) cnt++;
        }
    }
    return cnt;
}

int bfs(int x, int y, int dir){
    memset(vis, 0, sizeof(vis));
    queue<triple> q;
    vis[x][y] = 1;
    q.push({x, y, dir});
    while(!q.empty()){
        auto [x_, y_, d] = q.front();
        q.pop();
        int nx = x_ + dx[d];
        int ny = y_ + dy[d];
        if(nx < 0 || nx >= r || ny < 0 || ny >= c) continue;
        char pipe = board[nx][ny];
        if(pipe == 'Z') return count_vis_pipe();
        if(pipe == '.') break;
        vis[nx][ny] = 1;
        int n = pipe_n[pipe];
        int nd = pipe_route[n][d];
        if(nd == -1) return -1;
        q.push({nx, ny, nd});
    }
    return -1;
}

int main(){
    int x = 0, y = 0, pipe_cnt = 0;
    cin >> r >> c;
    for(int i = 0; i < r; i++){
        for(int j = 0; j < c; j++){
            cin >> board[i][j];
            if(board[i][j] != '.' && !isalpha(board[i][j])) pipe_cnt++;
            if(board[i][j] == 'M'){
                x = i;
                y = j;
            }
        }
    }
    int dir = find_dir(x, y);
    pair<int, int> a = find_blank(x, y, dir);
    cout << a.first + 1 << ' ' << a.second + 1 << ' ';
    //답이 |, - 일때 +는 순서에 의해 제외됨
    for(int i = 0; i < 7; i++){
        board[a.first][a.second] = pipes[i];
        int c = bfs(x, y, dir);
        if(c == -1) continue;
        if(c == pipe_cnt + 1){
            cout << pipes[i] << '\n';
            break;
        }
    }
}