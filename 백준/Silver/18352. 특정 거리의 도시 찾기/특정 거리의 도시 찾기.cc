#include <bits/stdc++.h>

using namespace std;

vector<int> edge[300001];
vector<int> ans;
queue<int>q;
int dist[300001];


int main(){
    ios::sync_with_stdio(0), cout.tie(0), cin.tie(0);
    int n, m, k, x;
    cin >> n >> m >> k >> x;
    fill(dist, dist + n + 1, -1);
    for (int i = 0; i < m; i++){
        int u, v;
        cin >> u >> v;
        edge[u].push_back(v);
    }
    
    q.push(x);
    dist[x] = 0;
    while(!q.empty()){
        auto cur = q.front();
        q.pop();
        for(auto nxt : edge[cur]){
            if(dist[nxt] != -1) continue;
            dist[nxt] = dist[cur] + 1;
            if(dist[nxt] == k) ans.push_back(nxt);
            q.push(nxt);
        }
    }
    sort(ans.begin(), ans.end());
    for (auto x : ans) cout << x << '\n';
    if (ans.empty()) cout << -1 << '\n';
}