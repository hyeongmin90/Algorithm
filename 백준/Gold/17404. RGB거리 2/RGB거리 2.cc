//boj 17404

#include <bits/stdc++.h>

using namespace std;

int cost[1001][3];
int dp[1001][3];
int ans = 0x7fffffff;

int main(){
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n; cin >> n;

    for(int i = 1; i <= n; i++){
        cin >> cost[i][0] >> cost[i][1] >> cost[i][2];
    }

    for(int j = 0; j < 3; j++){        
        dp[2][(j + 1) % 3] = cost[1][j] + cost[2][(j + 1) % 3];
        dp[2][(j + 2) % 3] = cost[1][j] + cost[2][(j + 2) % 3];
        dp[2][j] = 10001;
        for(int i = 3; i < n; i++){
            dp[i][0] = min(dp[i - 1][1], dp[i - 1][2]) + cost[i][0];
            dp[i][1] = min(dp[i - 1][0], dp[i - 1][2]) + cost[i][1];
            dp[i][2] = min(dp[i - 1][0], dp[i - 1][1]) + cost[i][2];
        }
        if(n == 2){
            ans = min(dp[n][(j + 1) % 3], dp[n][(j + 2) % 3]);
        }
        else{
            int a = dp[n][(j + 1) % 3] = min(dp[n - 1][j], dp[n - 1][(j + 2) % 3]) + cost[n][(j + 1) % 3];
            int b = dp[n][(j + 2) % 3] = min(dp[n - 1][j], dp[n - 1][(j + 1) % 3]) + cost[n][(j + 2) % 3];
            ans = min({ans, dp[n][(j + 1) % 3], dp[n][(j + 2) % 3]});
        }
    }
    cout << ans << '\n';
}