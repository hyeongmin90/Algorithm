#include <bits/stdc++.h>

using namespace std;

vector<int> adj[32001];
int deg[32001];
queue<int> q;

int main(){
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n, m;
    cin >> n >> m;
    for(int i = 0; i < m; i++){
        int u, v;
        cin >> u >> v;
        deg[v]++;
        adj[u].push_back(v);
    }
    for(int i = 1; i <= n; i++)
        if(deg[i] == 0) q.push(i);
    
    while(!q.empty()){
        auto cur = q.front(); q.pop();
        cout << cur << ' ';
        for(auto nxt : adj[cur]){
            deg[nxt]--;
            if(deg[nxt] == 0) q.push(nxt);
        }
    }
}