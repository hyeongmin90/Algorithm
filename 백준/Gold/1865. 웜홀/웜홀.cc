//boj 1865

#include <bits/stdc++.h>

using namespace std;

struct p
{
    int s;
    int e;
    int t;
};

int n, m, w;

void func(vector<p>& edges){
    vector<int> dist(n + 1, 0);
    dist[1] = 0;

    for(int i = 1; i < n; i++){
        for(int j = 0; j < edges.size(); j++){
            int s = edges[j].s;
            int e = edges[j].e;
            int t = edges[j].t;
            if(dist[e] > dist[s] + t) dist[e] = dist[s] + t;
        }
    }
    for(int j = 0; j < edges.size(); j++){
        int s = edges[j].s;
        int e = edges[j].e;
        int t = edges[j].t;
        if(dist[e] > dist[s] + t){
            cout << "YES" << '\n';
            return;
        }
    }
    cout << "NO" << '\n';
}

int main(){
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t;
    cin >> t;
    while(t--){
        vector<p> edges;
        int s, e, t;
        cin >> n >> m >> w;
        for(int i = 0; i < m; i++){
            cin >> s >> e >> t;
            edges.push_back({s, e, t});
            edges.push_back({e, s, t});
        }
        for(int i = 0; i < w; i++){
            cin >> s >> e >> t;
            edges.push_back({s, e, -t});
        }
        func(edges);
    }
}