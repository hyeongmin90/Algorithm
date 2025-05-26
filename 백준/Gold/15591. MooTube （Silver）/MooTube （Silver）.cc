#include <bits/stdc++.h>

using namespace std;

int usado[5001][5001];
vector<int> adj[5001];
queue<pair<int, int>> q;
int n;

void func(){
    for(int i = 1; i <= n; i++){
        bool visit[5001] = {};
        visit[i] = 1;
        q.push({i, 1000000001});
        while(!q.empty()){
            auto [cur, u] = q.front();
            q.pop();
            for(auto nxt : adj[cur]){
                if(visit[nxt]) continue;
                int min_val = min(u, usado[cur][nxt]);
                if(usado[i][nxt] == 0) usado[i][nxt] = min_val;
                visit[nxt] = 1;
                q.push({nxt, min_val});
            }
        }
    }
}

int main(){
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int q;
    cin >> n >> q;
    for(int i = 0; i < n - 1; i++){
        int u, v, r;
        cin >> u >> v >> r;
        usado[u][v] = r;
        usado[v][u] = r;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    func();
    for(int i = 0; i < q; i++){
        int k, v;
        cin >> k >> v;
        int cnt = 0;
        for(int i = 1; i <= n; i++){
            if(usado[v][i] >= k) cnt++;
        }
        cout << cnt << '\n';
    }
}