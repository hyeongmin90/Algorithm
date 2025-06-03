#include <bits/stdc++.h>

using namespace std;

struct p {
    int x, y, z;
};

int board[201][201];
queue<p> q;
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
vector<p> v;

bool compare(p a, p b){
    if(a.x != b.x) return a.x < b.x;
    if(a.y != b.y) return a.y < b.y;
    return a.z < b.z;
}

int main(){
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n, k;
    cin >> n >> k;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cin >> board[i][j];
            if(board[i][j] != 0) v.push_back({board[i][j], i, j});
        }
    }
    sort(v.begin(), v.end(), compare);
    for(auto [_, i, j] : v){
        q.push({i, j});
    }

    int s, x_, y_;
    cin >> s >> x_ >> y_;
    while(!q.empty()){
        auto [x, y, time] = q.front();
        if(time == s) break;
        q.pop();
        
        for(int dir = 0; dir < 4; dir++){
            int nx = x + dx[dir];
            int ny = y + dy[dir];
            if(nx < 0 || nx >= n || ny < 0 || ny >= n || board[nx][ny] != 0) continue;
            board[nx][ny] = board[x][y];
            q.push({nx, ny, time + 1});
        }
    }
    
    cout << board[x_ - 1][y_ - 1] << '\n';
}