#include <bits/stdc++.h>

using namespace std;

string board[51];
map<pair<int, int>, int> mp;
int dis[51][51];
queue<pair<int, int>> q;
vector<pair<int, int>> adj[251];
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
int n, m, cnt;

void bfs(int i, int j){
    memset(dis, -1, sizeof(dis));
    q.push({i, j});
    dis[i][j] = 0;
    while(!q.empty()){
        auto [x, y] = q.front();
        q.pop();
        for(int dir = 0; dir < 4; dir++){
            int nx = x + dx[dir];
            int ny = y + dy[dir];
            //미로는 벽으로 둘러쌓여있음
            if(board[nx][ny] == '1' || dis[nx][ny] != -1)continue;
            dis[nx][ny] = dis[x][y] + 1;
            if(board[nx][ny] == 'K'){
                adj[mp[{i, j}]].push_back({dis[nx][ny], mp[{nx, ny}]});
                adj[mp[{nx, ny}]].push_back({dis[nx][ny], mp[{i, j}]});
            }
            q.push({nx, ny});
        }
    }  
}

int mst(){
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    bool vis[251] = {};
    int ans = 0;
    pq.push({0, 0});
    while(!pq.empty()){
        auto [cost, cur] = pq.top();
        pq.pop();
        if(vis[cur])continue;
        vis[cur] = 1;
        ans += cost;
        for(auto x : adj[cur]) pq.push(x);
    }
    for(int i = 1; i <= m; i++)
        if(!vis[i]) return -1;
    
    return ans;
}

int main(){
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> n >> m;
    for(int i = 0; i < n; i++){
        cin >> board[i];
        for(int j = 0; j < n; j++){
            if(board[i][j] == 'K') mp[{i, j}] = ++cnt;
        }
    }

    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(board[i][j] == 'S' || board[i][j] == 'K') bfs(i, j);
        }
    }
    cout << mst() << '\n';
}