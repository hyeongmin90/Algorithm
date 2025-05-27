#include <bits/stdc++.h>

using namespace std;

vector<int> v[101];
int d[101][101];
bool vis[101];
int mn = 0x7fffffff, ans;

int main(){
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n, m;
    cin >> n >> m;
    for(int i = 0; i < m; i++){
        int s, e;
        cin >> s >> e;
        v[s].push_back(e);
        v[e].push_back(s);
    }
    for(int i = 1; i <= n; i++){
        queue<int> q;
        fill(vis, vis + n + 1, 0);
        q.push(i);
        vis[i] = 1;
        int cnt = 0;
        while(!q.empty()){
            auto cur = q.front();
            q.pop();
            for(auto nxt : v[cur]){
                if(vis[nxt])continue;
                vis[nxt] = 1;
                q.push(nxt);
                d[i][nxt] = d[i][cur] + 1;
                cnt += d[i][nxt];
            }
        }
        if(mn > cnt){
            mn = cnt;
            ans = i;
        }
    }
    cout << ans << '\n';
}