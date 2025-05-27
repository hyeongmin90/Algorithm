#include <bits/stdc++.h>
#define X first 
#define Y second

using namespace std;

vector<pair<int, int>> v[1001];
int ans[1001];
int dist[1001];
int INF = 0x3f3f3f3f;
int n, m, x;

void Dijkstra(int start){
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    fill(dist, dist + n + 1, INF);
    pq.push({0, start});
    dist[start] = 0;
    while(!pq.empty()){
        auto cur = pq.top();
        pq.pop();
        if(dist[cur.Y] != cur.X)continue;
        for(auto nxt : v[cur.Y]){
            if(dist[nxt.Y] < dist[cur.Y] + nxt.X)continue;
            dist[nxt.Y] = dist[cur.Y] + nxt.X;
            pq.push({dist[nxt.Y], nxt.Y});
        }
    }
}

int main(){
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> n >> m >> x;
    for(int i = 0; i < m; i++){
        int s, e, c;
        cin >> s >> e >> c;
        v[s].push_back({c, e});
    }
    for(int i = 1; i <= n; i++){
        Dijkstra(i);
        ans[i] += dist[x];
    }
    Dijkstra(x);
    for(int i = 1; i <= n; i++) ans[i] += dist[i];
    cout << *max_element(ans, ans + n + 1) << '\n';
}