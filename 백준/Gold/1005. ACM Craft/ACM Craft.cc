#include <bits/stdc++.h>

using namespace std;

int BuildTime[1002];
long long result[1002];

int main(){
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t; cin >> t;
    while(t--){
        vector<int> adj[1002];
        int deg[1002] = {};
        queue<int> q;
        int n, k;
        cin >> n >> k;
        for(int i = 1; i <= n; i++){
            cin >> BuildTime[i];
            result[i] = BuildTime[i];
        }
        for(int i = 0; i < k; i++){
            int x, y;
            cin >> x >> y;
            adj[x].push_back(y);
            deg[y]++;
        }   
        int goal;
        cin >> goal;

        for(int i = 1; i <= n; i++) if(deg[i] == 0) q.push(i);

        while(!q.empty()){
            auto cur = q.front(); q.pop();
            for(auto nxt : adj[cur]){
                deg[nxt]--;
                result[nxt] = max(result[nxt], result[cur] + BuildTime[nxt]);
                if(deg[nxt] == 0) q.push(nxt);
            }
        }
        cout << result[goal] << '\n';
    }
}