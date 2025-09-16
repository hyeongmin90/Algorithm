#include <bits/stdc++.h>

using namespace std;

vector<pair<int, int>> egg;
int n, ans;

void dfs(int depth){
    if(depth == n){
        int cnt = 0;
        for(int i = 0; i < n; i++){
            if(egg[i].first <= 0) cnt++;
        }
        ans = max(ans, cnt);
        return;
    }

    for(int i = 0; i < n; i++){
        if(egg[depth].first <= 0) dfs(depth + 1);
        else if(i == depth || egg[i].first <= 0) continue;
        else{
            egg[depth].first -= egg[i].second;
            egg[i].first -= egg[depth].second;
            dfs(depth + 1);
            egg[depth].first += egg[i].second;
            egg[i].first += egg[depth].second;
        }
    }
    int cnt = 0;
    for(int i = 0; i < n; i++){
        if(egg[i].first <= 0) cnt++;
    }
    ans = max(ans, cnt);
}

int main(){
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> n;
    for(int i = 0; i < n; i++){
        int a, b;
        cin >> a >> b;
        egg.push_back({a, b});
    }    
    dfs(0);
    cout << ans << '\n';
}