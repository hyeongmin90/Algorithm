#include <bits/stdc++.h>

using namespace std;

int deg[10001];
vector<int> adj[10001];
queue<int> q;
int tme[10001];
int arr[10001];

int main(){
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n;
    cin >> n;
    for(int i = 1; i <= n; i++){
        int t, m;
        cin >> t >> m;
        deg[i] = m;
        tme[i] = arr[i] = t;
        for(int j = 0; j < m; j++){
            int pre; cin >> pre;
            adj[pre].push_back(i);
        }
    }
    for(int i = 1; i <= n; i++) if(deg[i] == 0) q.push(i);

    while(!q.empty()){
        auto cur = q.front(); q.pop();
        for(auto nxt : adj[cur]){
            deg[nxt]--;
            arr[nxt] = max(arr[nxt], arr[cur] + tme[nxt]);
            if(deg[nxt] == 0) q.push(nxt); 
        }
    }

    cout << *max_element(arr + 1, arr + n + 1) << '\n';

}