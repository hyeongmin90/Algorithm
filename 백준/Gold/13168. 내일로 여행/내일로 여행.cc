#include <bits/stdc++.h>

using namespace std;

map<string, int> citys;
queue<int> q;
int cost[101][101];
int cost_t[101][101];
int INF = 0x3f3f3f3f;

int tiket_cost(string type, int cost){
    if(type == "Mugunghwa" || type == "ITX-Saemaeul" || type == "ITX-Cheongchun"){
        return 0;
    }
    else if(type == "V-Train" || type == "S-Train"){
        return cost / 2;
    }
    return cost;
}

int main(){
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n, r, m, k;
    cin >> n >> r;
    for(int i = 0; i < n; i++){
        fill(cost[i], cost[i] + n, INF);
        fill(cost_t[i], cost_t[i] + n, INF);
    }
    for(int i = 0; i < n; i++){
        string city;
        cin >> city;
        citys[city] = i;
    }
    cin >> m;
    for(int i = 0; i < m; i++){
        string city;
        cin >> city;
        q.push(citys[city]);
    }
    cin >> k;
    for(int i = 0; i < k; i++){
        string type, start, end;
        int c;
        cin >> type >> start >> end >> c;
        c *= 2;
        int u = citys[start];
        int v = citys[end];
        int cost_ = min(cost[u][v], c);
        cost[u][v] = cost_;
        cost[v][u] = cost_;
        int t_cost = min(cost_t[u][v], tiket_cost(type, c));
        cost_t[u][v] = t_cost;
        cost_t[v][u] = t_cost;
    }
    
    for(int u = 0; u < n; u++){
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                if(i == j) continue;
                cost[i][j] = min(cost[i][j], cost[i][u] + cost[u][j]);
                cost_t[i][j] = min(cost_t[i][j], cost_t[i][u] + cost_t[u][j]);
            }
        }
    }
    int cur = q.front();
    q.pop();
    long total = 0, total_t = 0;
    while(!q.empty()){
        int nxt = q.front();
        q.pop();
        // cout << cost[cur][nxt] << " " << cost_t[cur][nxt] << '\n';
        total += cost[cur][nxt];
        total_t += cost_t[cur][nxt];
        cur = nxt;
    }
    //cout << total << " " << total_t << " " << r << '\n';
    cout << (total_t + r * 2 < total ? "Yes" : "No") << '\n';
}