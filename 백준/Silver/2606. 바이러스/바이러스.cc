#include <bits/stdc++.h>

using namespace std;

vector<int> edges[101];
bool c[101];
queue<int> q;

int main(){
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n, edge;
    cin >> n >> edge;
    for(int i = 0; i < edge; i++){
        int s, e;
        cin >> s >> e;
        edges[s].push_back(e);
        edges[e].push_back(s);
    }
    c[1] = true;
    q.push(1);
    int cnt = 0;
    while(!q.empty()){
        auto cur = q.front();
        q.pop();
        for(auto x : edges[cur]){
            if(c[x])continue;
            c[x] = true;
            cnt++;
            q.push(x);
        }
    }
    cout << cnt << '\n';
}