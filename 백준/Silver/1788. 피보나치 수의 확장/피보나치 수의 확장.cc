#include <bits/stdc++.h>

using namespace std;

int dp[1000001];
int n;
int mod = 1000000000;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    cin >> n;
    dp[1] = 1;
    dp[2] = 1;
    for (int i = 3; i <= abs(n); i++)
        dp[i] = (dp[i - 1] + dp[i - 2]) % mod;

    if (n < 0 && n % 2 == 0)
        cout << -1;
    else if (n == 0)
        cout << 0;
    else
        cout << 1;

    cout << '\n' << dp[abs(n)];
    return 0;
}