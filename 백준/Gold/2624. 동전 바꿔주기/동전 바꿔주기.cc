#include <bits/stdc++.h>

using namespace std;

vector<pair<int, int>> coin;
int dp[10001];

int main(){
    int t, k;
    cin >> t >> k;
    for(int i = 0; i < k; i++){
        int p, n;
        cin >> p >> n;
        coin.push_back({p, n});
    }
    dp[0] = 1;

    for(int u = 0; u < k; u++){
        auto [p, n] = coin[u];
        for(int i = t; i >= 1; i--){
            for(int j = 1; j <= n; j++){
                if(p * j > i) break;
                dp[i] += dp[i - p * j];
            }
        }
    }
    cout << dp[t] << '\n';
    
}