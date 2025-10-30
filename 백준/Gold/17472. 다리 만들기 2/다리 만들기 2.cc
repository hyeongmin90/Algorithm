#include <bits/stdc++.h>

using namespace std;

struct p
{
    int x, y, d, start;
};


int n, m, k;
int board[11][11];
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
vector<pair<int, int>> v;
int edge[11][11];
int MAX = 0x7fffffff;

bool oob(int x, int y){
    return (x < 0 || x >= n || y < 0 || y >= m);
}

void numbering(){
    queue<pair<int, int>> q;
    bool vis[11][11] = {};
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(board[i][j] == 0 || vis[i][j]) continue;
            q.push({i, j});
            vis[i][j] = 1;
            k++;
            board[i][j] = k;
            v.push_back({i, j});
            while(!q.empty()){
                auto x = q.front();
                q.pop();
                for(int dir = 0; dir < 4; dir++){
                    int nx = x.first + dx[dir];
                    int ny = x.second + dy[dir];
                    if(oob(nx, ny)) continue;
                    if(vis[nx][ny] || board[nx][ny] == 0) continue;
                    q.push({nx, ny});
                    vis[nx][ny] = 1;
                    board[nx][ny] = board[x.first][x.second];
                    v.push_back({nx, ny});
                }
            }
        }
    }
}


void find_edge(){
    for(int i = 0; i < 11; i++)
        fill(edge[i], edge[i] + 11, MAX);

    for(auto a : v){
        int x = a.first;
        int y = a.second;
        for(int dir = 0; dir < 4; dir++){
            int cnt = 1;
            while(1){
                int nx = x + dx[dir] * cnt;
                int ny = y + dy[dir] * cnt;
                int dist = cnt - 1;
                cnt++;
                if(oob(nx, ny)) break;
                if(board[nx][ny] == board[x][y]) break;
                if(board[nx][ny] == 0) continue;
                if(board[nx][ny] != board[x][y]){
                    if(dist < 2) break;
                    edge[board[x][y]][board[nx][ny]] = min(dist, edge[board[x][y]][board[nx][ny]]);
                    edge[board[nx][ny]][board[x][y]] = min(dist, edge[board[x][y]][board[nx][ny]]);
                    break;
                }
            }
        }
    }
}

int mst(){
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    bool vis[11] = {};
    int ans = 0;
    vis[1] = 1;
    for(int i = 1; i <= k; i++){
        if(edge[1][i] == MAX) continue;
        pq.push({edge[1][i], i});
    }
    while(!pq.empty()){
        auto [d, nxt] = pq.top();
        pq.pop();
        if(vis[nxt]) continue;
        ans += d;
        vis[nxt] = 1;
        for(int i = 1; i <= k; i++){
            if(edge[nxt][i] == MAX) continue;
            pq.push({edge[nxt][i], i});
        }
    }
    for(int i = 1; i <= k; i++){
        if(!vis[i]) return -1;
    }
    return ans;
}

int main(){
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> n >> m;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin >> board[i][j];
        }
    }
    numbering();
    find_edge();
    cout << mst() << '\n';
}