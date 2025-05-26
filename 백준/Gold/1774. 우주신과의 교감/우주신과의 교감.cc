#include <bits/stdc++.h>

using namespace std;

pair<int, int> coord[1001];
vector<tuple<double, int, int>> edges;
double ans;
int p[1001];

int find(int x){
    if(p[x] < 0) return x;
    return p[x] = find(p[x]);
}

bool Union(int u, int v){
    u = find(u); v = find(v);
    if(u == v) return 0;
    if(p[u] == p[v]) p[u]--;
    if(p[u] < p[v]) p[v] = u;
    else p[u] = v;
    return 1;
}

int main(){
    int n, m;
    cin >> n >> m;
    for(int i = 1; i <= n; i++)
        cin >> coord[i].first >> coord[i].second;
    
    fill(p, p + n + 1, -1);
    
    for(int i = 1; i <= n; i++){
        for(int j = 1; j < i; j++){
            int a = abs(coord[i].first - coord[j].first);
            int b = abs(coord[i].second - coord[j].second);
            double d = hypot(a, b);
            edges.push_back({d, i, j});
        }
    }

    sort(edges.begin(), edges.end());

    int cnt = 0;
    for(int i = 0; i < m; i++){
        int u, v;
        cin >> u >> v;
        if(Union(u, v))cnt++;
    }
    
    if(cnt == n - 1){
        cout << "0.00" << '\n';
        return 0;
    }

    for(int i = 0; i < edges.size(); i++){
        double d;
        int u, v;
        tie(d, u, v) = edges[i];
        if(!Union(u, v)) continue;
        cnt++;
        ans += d;
        if(cnt == n - 1)break;
    }
    cout<<fixed;
    cout.precision(2);
    cout << ans << '\n';
}
