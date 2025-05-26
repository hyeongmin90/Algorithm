#include <bits/stdc++.h>

using namespace std;

vector<pair<int, int>> adj[1001];
priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
bool vis[1001];
int ans;

int main(){
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n, m, k;
    cin >> n >> m >> k;
    for(int i = 0; i < k; i++){
        int gen; cin >> gen;
        pq.push({0, gen});
    }
    for(int i = 0; i < m; i++){
        int u, v, c;
        cin >> u >> v >> c;
        adj[u].push_back({c, v});
        adj[v].push_back({c, u});
    }
    while(!pq.empty()){
        auto [cost, city] = pq.top();
        pq.pop();
        if(vis[city])continue;
        ans += cost;
        vis[city] = true;
        for(auto [c, nxt] : adj[city]){
            if(vis[nxt])continue;
            pq.push({c, nxt});
        }
    }
    cout << ans << '\n';
}