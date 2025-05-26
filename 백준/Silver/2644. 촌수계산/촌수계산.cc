//boj 2644
#include <bits/stdc++.h>

using namespace std;

vector<int> adj[101];
int arr[101];
queue<int> q;
int ans;

int main(){
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n, u, v, m;
    cin >> n >> u >> v >> m;
    fill(arr, arr + n + 1, -1);
    while(m--){
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    q.push(u);
    arr[u] = 0;
    while(!q.empty()){
        auto cur = q.front();
        q.pop();
        for(auto nxt : adj[cur]){
            if(arr[nxt] != -1)continue;
            q.push(nxt);
            arr[nxt] = arr[cur] + 1;
        }
    }
    cout << arr[v] << '\n';
}