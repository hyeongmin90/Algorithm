#include <bits/stdc++.h>
#define X first 
#define Y second
#define ll long

using namespace std;

vector<pair<int, int>> v[801];
ll dist[801][2];
ll INF = 0x7fffffffff;
ll n, e;

void Dijkstra(int start, int t){
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    dist[start][t] = 0;
    pq.push({0, start});
    while(!pq.empty()){
        auto cur = pq.top();
        pq.pop();
        if(dist[cur.Y][t] != cur.X)continue;
        for(auto nxt : v[cur.Y]){
            if(dist[nxt.Y][t] < dist[cur.Y][t] + nxt.X)continue;
            dist[nxt.Y][t] = dist[cur.Y][t] + nxt.X;
            pq.push({dist[nxt.Y][t], nxt.Y});
        }
    }
}

int main(){
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> n >> e;
    for(int i = 0; i < e; i++){
        int s, e, t;
        cin >> s >> e >> t;
        v[s].push_back({t, e});
        v[e].push_back({t, s});
    }
    int n1, n2;
    cin >> n1 >> n2;
    for(int i = 0; i <= n; i++){
        dist[i][0] = INF;
        dist[i][1] = INF;
    }
    Dijkstra(n1, 0);
    Dijkstra(n2, 1);
    ll a = dist[1][0] + dist[n][1];
    ll b = dist[1][1] + dist[n][0];
    ll ans = min(a, b) + dist[n1][1];
    if(ans >= INF) cout << -1;
    else cout << ans << '\n';
}