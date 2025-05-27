//boj 1197

#include <bits/stdc++.h>

using namespace std;

vector<pair<int, int>> V[10001];

priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
bool visited[10001];

int main(){
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int v, e;
    cin >> v >> e;
    for(int i = 0; i < e; i++){
        int a, b, c;
        cin >> a >> b >> c;
        V[a].push_back({c, b});
        V[b].push_back({c, a});
    }

    visited[1] = 1;
    for(auto x : V[1]) pq.push(x);

    int ans = 0;

    while(!pq.empty()){
        pair<int, int> a = pq.top();
        visited[a.second] = 1;
        ans += a.first;
        pq.pop();
        for(auto x : V[a.second]) pq.push(x);
        while(!pq.empty() && visited[pq.top().second])
            pq.pop();
    }

    cout << ans << '\n';
}