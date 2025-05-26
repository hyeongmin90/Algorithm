#include <bits/stdc++.h>

using namespace  std;

vector<pair<int, int>> adj[301];
priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
bool vis[301];
int ans;

int main(){
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n; cin >> n;
    for(int i = 1; i <= n; i++){
        int cost; cin >> cost;
        adj[0].push_back({cost, i});
        adj[i].push_back({cost, 0});
    }

    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            int cost; cin >> cost;
            if(j <= i) continue;
            adj[i].push_back({cost, j});
            adj[j].push_back({cost, i});
        }
    }

    vis[1] = true;
    for(auto x : adj[1]) pq.push(x);

    while(!pq.empty()){
        auto cur = pq.top(); pq.pop();
        if(vis[cur.second]) continue;
        ans += cur.first;
        vis[cur.second] = true;
        for(auto nxt : adj[cur.second]) if(!vis[nxt.second]) pq.push(nxt);
    }
    cout << ans << '\n';

}