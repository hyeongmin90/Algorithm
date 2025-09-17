#include <bits/stdc++.h>

using namespace std;

int n, m;
vector<int> adj[2001];
bool vis[2001];

void dfs(int depth, int cur){
    if(depth == 5){
        cout << 1 << '\n';
        exit(0);
    }
    for(int nxt : adj[cur]){
        if(vis[nxt]) continue;
        vis[nxt] = true;
        dfs(depth + 1, nxt);
        vis[nxt] = false;
    }
}

int main(){
    ios::sync_with_stdio(0), cout.tie(0), cin.tie(0);
    cin >> n >> m;
    for(int i = 0; i < m; i++){
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }    
    for(int i = 0; i < n; i++){
        dfs(0, i);
    }
    cout << 0 << '\n';
}