#include <bits/stdc++.h>

using namespace std;

int dist[2001];
int INF = 0x3f3f3f3f;

void func(){
    bool passed[2001] = {};
    vector<pair<int, int>> edge[2001];
    vector<int> candidates;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    int n, m, t, s, g, h;
    cin >> n >> m >> t >> s >> g >> h;
    fill(dist + 1, dist + n + 1, INF);
    for(int i = 0; i < m; i++){
        int a, b, d;
        cin >> a >> b >> d;
        edge[a].push_back({d, b});
        edge[b].push_back({d, a});
    }
    for(int i = 0; i < t; i++){
        int x;
        cin >> x;
        candidates.push_back(x);
    }

    dist[s] = 0;
    pq.push({0, s});
    while(!pq.empty()){
        auto [d, cur] = pq.top();
        pq.pop();
        if(dist[cur] != d) continue;
        for(auto [cost, nxt] : edge[cur]){
            if(dist[nxt] < dist[cur] + cost) continue;
            if(dist[nxt] == dist[cur] + cost){
                if(!passed[nxt]) passed[nxt] = ((cur == g && nxt == h) || (cur == h && nxt == g) || passed[cur]);
            }
            else {
                passed[nxt] = ((cur == g && nxt == h) || (cur == h && nxt == g) || passed[cur]);
                dist[nxt] = dist[cur] + cost;
                pq.push({dist[nxt], nxt});
            }
        }
    }
    sort(candidates.begin(), candidates.end());
    for(int x : candidates)
        if(passed[x]) cout << x << ' ';
}

int main(){
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t;
    cin >> t;
    while(t--){
        func();
    }
}