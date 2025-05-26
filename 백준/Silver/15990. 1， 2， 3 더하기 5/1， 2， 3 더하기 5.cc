//boj 15990

#include <bits/stdc++.h>
#define mod 1000000009
#define MAXN 100001

using namespace std;

long long dp[MAXN][4];

int main(){

    dp[1][1] = 1;
    dp[2][2] = 1;
    dp[3][1] = dp[3][2] = dp[3][3] = 1;

    for(int i = 4; i < MAXN; i++){
        dp[i][1] = (dp[i - 1][2] + dp[i - 1][3]) % mod;
        dp[i][2] = (dp[i - 2][1] + dp[i - 2][3]) % mod;
        dp[i][3] = (dp[i - 3][1] + dp[i - 3][2]) % mod;
    }

    int t; cin >> t;
    for(int i = 0; i < t; i++){
        int n; cin >> n;
        cout << (dp[n][1] + dp[n][2] + dp[n][3]) % mod << '\n';
    }
}