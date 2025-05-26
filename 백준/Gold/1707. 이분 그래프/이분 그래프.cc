#include <bits/stdc++.h>

using namespace std;

int color[20001];

void solve(){
    queue<int> q;
    fill(color, color + 20001, -1);
    vector<int> adj[20001];
    int v, e;
    cin >> v >> e;
    for(int i = 0; i < e; i++){
        int u, v;
        cin >> u >> v;
        adj[v].push_back(u);
        adj[u].push_back(v);
    }
    for(int i = 1; i <= v; i++){
        if(color[i] != -1)continue;
        q.push(i);
        color[i] = 0;
        while(!q.empty()){
        auto cur = q.front(); q.pop();
        for(auto nxt : adj[cur]){
            if(color[nxt] == color[cur]) {
                cout << "NO" << '\n';
                return;
            }
            if(color[nxt] != -1)continue;
            color[nxt] = !color[cur];
            q.push(nxt);
            }
        }
    }
    cout << "YES" << '\n';
}

int main(){
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t; cin >> t;
    while(t--){
        solve();
    }
}