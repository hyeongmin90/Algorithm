#include <bits/stdc++.h>
#define X first
#define Y second

using namespace std;

vector<pair<int, int>> v[100001];
priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
bool visited[100001];
int ans;
int mx;

int main(){
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n, m;
    cin >> n >> m;
    for(int i = 0; i < m; i++){
        int a, b, c;
        cin >> a >> b >> c;
        v[a].push_back({c, b});
        v[b].push_back({c, a});
    }

    for(auto x : v[1]) pq.push(x);
    visited[1] = true;

    while(!pq.empty()){
        auto a = pq.top();
        pq.pop();
        if(visited[a.Y]) continue;
        visited[a.Y] = true;
        for(auto x : v[a.Y]) pq.push(x);
        ans += a.X;
        mx = max(mx, a.X);
    }
    cout << ans - mx << '\n';
}