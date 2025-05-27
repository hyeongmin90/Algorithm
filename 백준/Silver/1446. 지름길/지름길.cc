#include <bits/stdc++.h>

using namespace std;

int dp[10001];
vector<pair<int, int>> v[10001];

int main(){
    int n, d;
    cin >> n >> d;
    fill(dp, dp + d + 1, 10001);
    for(int i = 0; i < n; i++){
        int st, ed, dist;
        cin >> st >> ed >> dist;
        if(ed > d) continue;
        v[st].push_back({ed, dist});
    }
    dp[0] = 0;
    for(auto [to, dist] : v[0]) dp[to] = min(dp[to], 0 + dist);

    for(int i = 1; i <= d; i++){
        dp[i] = min(dp[i], dp[i - 1] + 1);
        if(!v[i].empty()){
            for(auto [to, dist] : v[i]) dp[to] = min(dp[to], dp[i] + dist);
        }
    }

    cout << dp[d] << '\n';
}