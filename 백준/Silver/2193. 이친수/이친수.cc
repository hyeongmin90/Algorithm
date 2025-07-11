#include <iostream>
#include <algorithm>

using namespace std;

long long dp[95];
int n;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    cin >> n;
    dp[1] = 1;
    dp[2] = 1;
    for (int i = 3; i <= n; i++){
        dp[i] = dp[i - 1] + dp[i - 2];
    }
    cout << dp[n];

    return 0;
}