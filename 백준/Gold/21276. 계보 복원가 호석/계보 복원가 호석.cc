#include <bits/stdc++.h>

using namespace std;

string name[1001];
unordered_map<string, int> id;
int deg[1001];
vector<int> adj[1001];
queue<int> q;
vector<string> root, ans[1001];

int main(){
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n, m;
    cin >> n;
    for(int i = 0; i < n; i++)
        cin >> name[i];
    
    sort(name, name + n);

    for(int i = 0; i < n; i++)
        id[name[i]] = i;

    cin >> m;
    for(int i = 0; i < m; i++){
        string a, b;
        cin >> a >> b;
        adj[id[b]].push_back(id[a]);
        deg[id[a]]++;
    }
    for(int i = 0; i < n; i++)
        if(deg[i] == 0){
            q.push(i);
            root.push_back(name[i]);
        }

    while(!q.empty()){
        auto cur = q.front(); q.pop();
        for(auto nxt : adj[cur]){
            deg[nxt]--;
            if(deg[nxt] == 0){
                q.push(nxt);
                ans[cur].push_back(name[nxt]);
            }
        }
    }
    cout << root.size() << '\n';
    for(auto x : root) cout << x << ' ';
    cout << '\n';

    for(int i = 0; i < n; i++){
        cout << name[i] << ' ' << ans[i].size() << ' ';
        sort(ans[i].begin(), ans[i].end());
        for(auto x : ans[i]) cout << x << ' ';
        cout << '\n';
    }
    
}