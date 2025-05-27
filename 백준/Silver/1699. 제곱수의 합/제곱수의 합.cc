#include <bits/stdc++.h>

using namespace std;

int dp[100001];
int n;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    cin >> n;
    fill(dp, dp + n + 1, 100);
    for (int i = 1; i * i <= n; i++)
        dp[i * i] = 1;
    dp[2] = 2;
    dp[3] = 3;
    for (int i = 1; i <= n; i++)
    {
        if (dp[i] == 1)
            continue;
        
        for (int j = 2; j * j < i; j++)
            dp[i] = min(dp[i], dp[j * j] + dp[i - j * j]);
        
    }
    cout << dp[n];
    return 0;
}