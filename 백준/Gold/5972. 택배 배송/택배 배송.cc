#include <bits/stdc++.h>

using namespace std;

vector<pair<int, int>> edge[50001];
priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
int node[50001];
int INF = 0x3f3f3f3f;

int main(){
    int n, m;
    cin >> n >> m;
    for(int i = 0; i < m; i++){
        int a, b, c;
        cin >> a >> b >> c;
        edge[a].push_back({c, b});
        edge[b].push_back({c, a});
    }
    fill(node + 1, node + n + 1, INF);
    node[1] = 0;
    pq.push({0, 1});
    while(!pq.empty()){
        auto cur = pq.top();
        pq.pop();
        if(node[cur.second] != cur.first) continue;
        for(auto [cost, nxt] : edge[cur.second]){
            if(node[nxt] <= node[cur.second] + cost) continue;
            node[nxt] = node[cur.second] + cost;
            pq.push({node[nxt], nxt});
        }
    }
    cout << node[n] << '\n';
}