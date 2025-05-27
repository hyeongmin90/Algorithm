#include <bits/stdc++.h>

using namespace std;

vector<int> adj[32001];
int deg[32001];
priority_queue<int, vector<int>, greater<int>> pq;

int main(){
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n, m;
    cin >> n >> m;
    for(int i = 0; i < m; i++){
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        deg[v]++;
    }
    for(int i = 1; i <= n; i++) if(deg[i] == 0) pq.push(i);

    while(!pq.empty()){
        auto cur = pq.top(); pq.pop();
        cout << cur << ' ';
        for(auto nxt : adj[cur]){
            deg[nxt]--;
            if(deg[nxt] == 0) pq.push(nxt);
        }
    }
}