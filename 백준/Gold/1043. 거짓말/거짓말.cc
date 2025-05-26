#include <bits/stdc++.h>

using namespace std;

vector<int> party[51];
vector<int> joinParty[51];
queue<int> q;
bool check[51];
bool vis[51];

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    int k; cin >> k;
    for(int i = 0; i < k; i++){
        int a; cin >> a;
        q.push(a);
        vis[a] = 1;
    }
    for(int i = 1; i <= m; i++){
        int u; cin >> u;
        for(int j = 0; j < u; j++){
            int a; cin >> a;
            party[i].push_back(a);
            joinParty[a].push_back(i);
        }
    }
    while(!q.empty()){
        auto cur = q.front();
        q.pop();
        for(auto p : joinParty[cur]){
            if(check[p]) continue;
            check[p] = 1;
            for(auto x : party[p]){
                if(vis[x]) continue;
                q.push(x);
                vis[x] = 1;
            }
        }
    }
    int ans = 0;
    for(int i = 1; i <= m; i++){
        if(!check[i]) ans++;
    }
    cout << ans << '\n';
}