#include <bits/stdc++.h>

using namespace std;

string gear[1001];
int t, n;

void gear_rotate(int g, int dir){
    bool vis[1001] = {};
    queue<pair<int, int>> q;
    q.push({g, dir});
    vis[g] = 1;
    while(!q.empty()){
        auto [cur, dir] = q.front();
        q.pop();
        for(int nxt : {cur + 1, cur - 1}){
            if(nxt < 1 || nxt > t) continue;
            if(vis[nxt]) continue;
            vis[nxt] = 1;
            int cur_pos = (nxt < cur) ? 6 : 2;
            int nxt_pos = (nxt < cur) ? 2 : 6;
            if(gear[cur][cur_pos] != gear[nxt][nxt_pos]) {
                q.push({nxt, dir * -1});
            }
        }
        int a = (dir == -1 ? 1 : 7);
        rotate(gear[cur].begin(), gear[cur].begin() + a, gear[cur].end());
    }
}

int main(){
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> t;
    for(int i = 1; i <= t; i++){
        cin >> gear[i];
    }
    cin >> n;
    for(int i = 0; i < n; i++){
        int g, d;
        cin >> g >> d;
        gear_rotate(g, d);
    }
    int ans = 0;
    for(int i = 1; i <= t; i++){
        if(gear[i][0] == '1') ans++;
    }
    cout << ans << '\n';
}