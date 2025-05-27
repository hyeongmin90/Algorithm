#include <bits/stdc++.h>
#define X first 
#define Y second
 
using namespace std;

int INF = 0x3f3f3f3f;
vector<pair<int, int>> v[1001];
int dist[1001];
bool fix[1001];

int main(){
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n, m;
    cin >> n >> m;
    for(int i = 0; i < m; i++){
        int s, e, t;
        cin >> s >> e >> t;
        v[s].push_back({t, e});
    }
    int start, end;
    cin >> start >> end;
    fill(dist, dist + n + 1, INF);
    dist[start] = 0;
    while(1){
        int idx = -1;
        for(int i = 1; i <= n; i++){
            if(fix[i])continue;
            if(idx == -1) idx = i;
            else if(dist[i] < dist[idx]) idx = i;
        }
        if(idx == -1 || dist[idx] == INF)break;
        fix[idx] = 1;
        for(auto nxt : v[idx]){
            dist[nxt.Y] = min(dist[nxt.Y], dist[idx] + nxt.X);
        }
    }
    cout << dist[end] << '\n';
}