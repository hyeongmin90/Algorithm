#include <bits/stdc++.h>

using namespace std;

int n;
int dp[31];

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    cin >> n;
    if (n % 2 != 0)
    {
        cout << 0;
        return 0;
    }
    dp[0] = 1;
    dp[2] = 3;
    for (int i = 3; i <= n; i++)
    {
        dp[i] += dp[i - 2] * 3;
        for (int j = i - 4; j >= 0; j -= 2)
        {
            dp[i] += dp[j] * 2;
        }
    }
    cout << dp[n];
    return 0;
}