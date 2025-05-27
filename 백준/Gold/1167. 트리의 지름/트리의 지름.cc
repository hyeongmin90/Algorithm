#include <bits/stdc++.h>

using namespace std;

bool vis[100001];
vector<pair<int, int>> v[100001];
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
    for(int i = 0; i < n; i++){
        int num;
        cin >> num;
        while(1){
            int m;
            cin >> m;
            if(m == -1)break;
            int dist;
            cin >> dist;

            v[num].push_back({m, dist});
        }
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