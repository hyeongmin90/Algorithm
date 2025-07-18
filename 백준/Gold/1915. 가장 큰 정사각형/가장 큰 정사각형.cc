#include <bits/stdc++.h>

using namespace std;

int n, m;
int dp[1005][1005];
int ans;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        string num;
        cin >> num;
        for (int j = 1; j <= m; j++)
            dp[i][j] = num[j - 1] - '0';
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if(!dp[i][j])continue;
            dp[i][j] = min({dp[i - 1][j], dp[i][j - 1], dp[i - 1][j - 1]}) + 1;
            ans = max(ans, dp[i][j]);
        }
    }
    cout << ans * ans;
    return 0;
}