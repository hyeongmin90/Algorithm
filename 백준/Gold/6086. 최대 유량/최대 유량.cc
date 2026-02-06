#include <bits/stdc++.h>

using namespace std;

int n;
int capacity[60][60];
int flow[60][60];
vector<int> edge[60];
int vis[60];

int maximum_flow(int start, int end){
    int ans = 0;
    while(1){
        memset(vis, -1, sizeof(vis));
        queue<int> q;
        q.push(start);
        while(!q.empty()){
            auto cur = q.front();
            q.pop();

            for(auto nxt : edge[cur]){
                if(vis[nxt] != -1 || capacity[cur][nxt] - flow[cur][nxt] <= 0) continue;
                q.push(nxt);
                vis[nxt] = cur;
                if(nxt == end) break;
            }
            if(vis[end] != -1) break;
        }
        if(vis[end] == -1) break;
        
        int remaining = 0, tmp_max = 0x3f3f3f3f;
        for(int i = end; i != start; i = vis[i]){
            remaining = capacity[vis[i]][i] - flow[vis[i]][i];
            tmp_max = min(tmp_max, remaining);
        }

        for(int i = end; i != start; i = vis[i]){
            flow[vis[i]][i] += tmp_max;
            flow[i][vis[i]] -= tmp_max;
        }
        ans += tmp_max;
    }
    return ans;
}


int func(char a){
    if(a >= 'A' && a <= 'Z') return a - 'A';
    return a - 'a' + 26;
}

int main(){
    cin >> n;
    for(int i = 0; i < n; i++){
        char a, b;
        int c;
        cin >> a >> b >> c;
        int u = func(a);
        int v = func(b);
        capacity[u][v] += c;
        capacity[v][u] += c;
        edge[u].push_back(v);
        edge[v].push_back(u);
    }
    cout << maximum_flow(func('A'), func('Z')) << '\n';
}