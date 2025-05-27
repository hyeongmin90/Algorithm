#include <bits/stdc++.h>

using namespace std;

vector<int> adj[1001];
int deg[1001];
queue<int> q;
vector<int> ans;

int main(){
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n, m;
    cin >> n >> m;
    while(m--){
        int a; cin >> a;
        int pre = 0;
        for(int i = 0; i < a; i++){
            int s; cin >> s;
            if(i != 0){
                adj[pre].push_back(s);
                deg[s]++;
            }
            pre = s;
        }
    }
    for(int i = 1; i <= n; i++)
        if(deg[i] == 0) q.push(i);

    while(!q.empty()){
        auto cur = q.front(); q.pop();
        ans.push_back(cur);
        for(auto nxt : adj[cur]){
            deg[nxt]--;
            if(deg[nxt] == 0)q.push(nxt);
        }
    }
    if(ans.size() != n) cout << 0 << '\n';
    else for(auto x : ans) cout << x << '\n';
}