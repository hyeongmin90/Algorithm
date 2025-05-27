#include <bits/stdc++.h>

using namespace std;

int outdeg[101];
int indeg[101];
vector<pair<int, int>> adj[101];
queue<pair<int, int>> q;

int main(){
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n, m;
    cin >> n >> m;
    for(int i = 0; i < m; i++){
        int part, pre, cnt;
        cin >> part >> pre >> cnt;
        indeg[pre] += cnt;
        adj[part].push_back({pre, cnt}); 
    }
    outdeg[n] = 1;
    q.push({n, 1});

    while(!q.empty()){
        auto cur = q.front(); q.pop();
        for(auto nxt : adj[cur.first]){
            indeg[nxt.first] -= nxt.second;
            outdeg[nxt.first] += nxt.second * outdeg[cur.first];
            if(indeg[nxt.first] == 0) q.push({nxt.first, outdeg[nxt.first]});
        }
    }
    for(int i = 1; i < n; i++){
        if(adj[i].size() == 0) cout << i << ' ' << outdeg[i] << '\n';
    }

}