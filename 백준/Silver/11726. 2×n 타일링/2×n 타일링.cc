#include <iostream>
#include <algorithm>

using namespace std;

int dp[1005];
int n;
int mod = 10007;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    dp[1] = 1;
    dp[2] = 2;
    cin >> n;
    for (int i = 3; i <= n; i++){
        dp[i] = (dp[i - 2] + dp[i - 1]) % mod;
    }
    cout << dp[n];
    return 0;
}