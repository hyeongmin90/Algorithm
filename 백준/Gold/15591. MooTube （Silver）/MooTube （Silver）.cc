#include <bits/stdc++.h>

using namespace std;

vector<pair<int, int>> adj[5001];
queue<pair<int, int>> q;
int n;

int func(int k, int i){
    int result = 0;
    bool visit[5001] = {};
    visit[i] = 1;
    q.push({i, k});
    while(!q.empty()){
        auto [cur, u] = q.front();
        q.pop();
        for(auto [nxt, usado] : adj[cur]){
            if(visit[nxt]) continue;
            int min_val = min(u, usado);
            if(min_val < k) continue;
            result++;
            visit[nxt] = 1;
            q.push({nxt, min_val});
        }
    }
    return result;
}

int main(){
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int q;
    cin >> n >> q;
    for(int i = 0; i < n - 1; i++){
        int u, v, r;
        cin >> u >> v >> r;
        adj[u].push_back({v, r});
        adj[v].push_back({u, r});
    }

    for(int i = 0; i < q; i++){
        int k, v;
        cin >> k >> v;
        cout << func(k, v) << '\n';
    }
}