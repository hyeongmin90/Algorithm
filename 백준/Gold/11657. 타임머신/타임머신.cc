#include <bits/stdc++.h>

using namespace std;

struct l
{
    int a, b, cost;
};

vector<l> v;
long long dist[501];
int INF = 0x3f3f3f3f;

int main(){
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n, m;
    cin >> n >> m;
    fill(dist, dist + n + 1, INF);
    dist[1] = 0;

    for(int i = 0; i < m; i++){
        int a, b, c;
        cin >> a >> b >> c;
        v.push_back({a, b, c});
    }

    for(int i = 0; i < n - 1; i++){
        for(auto x : v){
            auto [a, b, cost] = x;
            if(dist[a] == INF) continue;
            dist[b] = min(dist[b], dist[a] + cost);
        }
    }
    for(auto x: v){
        auto [a, b, cost] = x;
        if(dist[a] == INF) continue;
        if(dist[b] > dist[a] + cost){
            cout << -1 << '\n';
            return 0;
        }
    }
    for(int i = 2; i <= n; i++){
        cout << (dist[i] == INF ? -1 : dist[i]) << '\n';
    }
}