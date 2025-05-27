#include <bits/stdc++.h>

using namespace std;

vector<pair<int, int>> adj[1001];
priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
pair<int, int> dis[1001];
int INF = 0x3f3f3f3f;


int main(){
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n, m;
    cin >> n >> m;
    fill(dis, dis + n + 1, make_pair(INF, 0));
    for(int i = 0; i < m; i++){
        int a, b, c;
        cin >> a >> b >> c;
        adj[a].push_back({c, b});
        adj[b].push_back({c, a});
    }
    dis[1] = {0, 0};
    pq.push({0, 1});
    while(!pq.empty()){
        auto [cost, cur] = pq.top();
        pq.pop();
        if(dis[cur].first != cost)continue;
        for(auto [c, nxt] : adj[cur]){
            if(dis[nxt].first < dis[cur].first + c)continue;
            dis[nxt].first = dis[cur].first + c;
            dis[nxt].second = cur;
            pq.push({dis[nxt].first, nxt});
        }
    }
    cout << n - 1 << '\n';
    for(int i = 2; i <= n; i++){
        cout << i << ' ' << dis[i].second << '\n';
    }
}