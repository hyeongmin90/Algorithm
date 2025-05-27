#include <bits/stdc++.h>

using namespace std;

vector<int> v[10004];
bool vis[10004];
int d[10004];
int mx;

void func(int n){
    vis[n] = true;
    d[n]++;
    mx = max(mx, d[n]);
    for(auto nxt : v[n]){
        if(vis[nxt]) continue;
        func(nxt);
    }
}

int main(){
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n, m;
    cin >> n >> m;
    for(int i = 0; i < m; i++){
        int s, e;
        cin >> s >> e;
        v[s].push_back(e);
    }
    for(int i = 1; i <= n; i++){
        fill(vis, vis + n + 1, 0);
        func(i);
    }

    for(int i = 1; i <= n; i++)
        if(d[i] == mx) cout << i << ' ';
    
}