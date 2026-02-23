#include <bits/stdc++.h>

using namespace std;

int n, m;
int board[51][51];
int dx[8] = {0, -1, -1, -1, 0, 1, 1, 1};
int dy[8] = {-1, -1, 0, 1, 1, 1, 0, -1};
queue<pair<int, int>> cloud;

int wrap(int a){
    if(a < 0) return a + n;
    else if(a >= n) return a % n;
    return a;
}

void solution(int dir, int dist){
    vector<pair<int, int>> v;
    set<pair<int, int>> s;
    while(!cloud.empty()){
        auto cur = cloud.front();
        cloud.pop();
        int nx = cur.first;
        int ny = cur.second;
        for(int i = 0; i < dist; i++){
            nx += dx[dir];
            ny += dy[dir];
            nx = wrap(nx);
            ny = wrap(ny);
        }
        v.push_back({nx, ny});
        board[nx][ny]++;
        s.insert({nx, ny});
    }

    for(auto [x, y] : v){
        int cnt = 0;
        for(int i = 1; i < 8; i += 2){
            int nx = x + dx[i];
            int ny = y + dy[i];
            if(nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
            if(board[nx][ny] > 0) cnt++;
        }
        board[x][y] += cnt;
    }


    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(board[i][j] < 2) continue;
            if(s.find({i, j}) != s.end()) continue;
            board[i][j] -= 2;
            cloud.push({i, j});
        }
    }
}

int main(){
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> n >> m;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cin >> board[i][j];
        }
    }

    cloud.push({n - 1, 0});
    cloud.push({n - 1, 1});
    cloud.push({n - 2, 0});
    cloud.push({n - 2, 1});

    for(int i = 0; i < m; i++){
        int d, s;
        cin >> d >> s;
        solution(d - 1, s);
    }
    int ans = 0;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            ans += board[i][j];
        }
    }
    cout << ans << '\n';

}