#include <bits/stdc++.h>

using namespace std;

pair<int, int> house[51];
bool chk[51];
int shelter[3];
int n, k, ans = 0x7fffffff;

void func(){
    int max_dist = 0;
    for(int i = 0; i < n; i++){
        int min_dist = 0x7fffffff;
        for(int j = 0; j < k; j++){
            auto [x, y] = house[i];
            int nx = abs(x - house[shelter[j]].first);
            int ny = abs(y - house[shelter[j]].second);
            int dist = nx + ny;
            min_dist = min(min_dist, dist);
        }
        max_dist = max(max_dist, min_dist);
    }
    ans = min(ans, max_dist);
}

void dfs(int depth){
    if(depth == k){
        func();
        return;
    }
    for(int i = 0; i < n; i++){
        if(chk[i]) continue;
        chk[i] = true;
        shelter[depth] = i;
        dfs(depth + 1);
        chk[i] = false;
    }
}

int main(){
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> n >> k;
    for(int i = 0; i < n; i++){
        int a, b;
        cin >> a >> b;
        house[i] = {a, b};
    }
    dfs(0);
    cout << ans << '\n';
}



