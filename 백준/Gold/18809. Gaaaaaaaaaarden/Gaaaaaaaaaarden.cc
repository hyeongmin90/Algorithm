#include <bits/stdc++.h>

using namespace std;

struct triple { 
    int x, y, c;
};


int n, m, g, r, ans;
int garden[52][52];
vector<pair<int, int>> v;
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

int simulation(const vector<int>& sequence){
    queue<triple> q;
    pair<int, int> dist[52][52] = {};

    for(int i = 0; i < v.size(); i++){
        if(sequence[i] == 0) continue;
        int x = v[i].first, y = v[i].second;
        q.push({x, y, sequence[i]});
        dist[x][y] = {1, sequence[i]};
    }
    int flower = 0;
    while(!q.empty()){
        auto [x, y, c] = q.front();
        q.pop();
        if(dist[x][y].second == 3) continue;
        for(int dir = 0; dir < 4; dir++){
            int nx = x + dx[dir];
            int ny = y + dy[dir];
            if(nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
            if(garden[nx][ny] == 0) continue;
            if(dist[nx][ny].second != c && dist[nx][ny].first == dist[x][y].first + 1){
                dist[nx][ny] = {-1, 3};
                flower++;
                continue;
            }
            if(dist[nx][ny].first != 0) continue;
            dist[nx][ny] = {dist[x][y].first + 1, c};
            q.push({nx, ny, c});
        }
    }
    return flower;
}

int main(){
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> n >> m >> g >> r;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin >> garden[i][j];
            if(garden[i][j] == 2) v.push_back({i, j});
        }
    }

    vector<int> sequence(v.size());
    fill_n(sequence.begin(), g, 1);
    fill_n(sequence.begin() + g, r, 2);
    sort(sequence.begin(), sequence.end());
    
    do
    {
        int cnt = simulation(sequence);
        ans = max(ans, cnt);
    } while (next_permutation(sequence.begin(), sequence.end()));
    
    cout << ans << '\n';
}