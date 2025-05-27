#include <bits/stdc++.h>

using namespace std;

bool vis[10001];
vector<pair<int, int>> v[10001];
int ans;
int root, root2;

void dfs(int n, int sum){
    if(n != root && v[n].size() == 1){
        if(ans < sum){
            ans = sum;
            root2 = n;
        }
        return;
    }
    for(int i = 0; i < v[n].size(); i++){
        if(vis[v[n][i].first]) continue;
        vis[v[n][i].first] = true;
        dfs(v[n][i].first, sum + v[n][i].second);
    }
}

int main(){
    int n; cin >> n;
    for(int i = 0; i < n - 1; i++){
        int a, b, dist;
        cin >> a >> b >> dist;
        v[a].push_back({b, dist});
        v[b].push_back({a, dist});
    }  
    
    for(int i = 1; i <= n; i++){
        if(v[i].size() == 1){
            root = i;
            break;
        }
    }
    vis[root] = 1;
    dfs(root, 0);
    memset(vis, 0, sizeof(vis));
    root = root2;
    dfs(root, 0);
    cout << ans << '\n';

}