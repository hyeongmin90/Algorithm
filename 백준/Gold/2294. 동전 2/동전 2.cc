#include <bits/stdc++.h>

using namespace std;

int n, k;
int dp[10001];
vector<int> v;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    cin >> n >> k;
    while (n--)
    {
        int val;
        cin >> val;
        v.push_back(val);
    }
    sort(v.begin(), v.end());
    v.erase(unique(v.begin(), v.end()), v.end());
    fill(dp + 1, dp + k + 1, 10002);
    
    for (int i = 0; i < v.size(); i++)
    {
        for (int j = 1; j <= k; j++)
        {
            if (j < v[i])
                continue;
            dp[j] = min(dp[j], dp[j - v[i]] + 1);
        }
    }
    cout << (dp[k] == 10002 ? -1 : dp[k]);

    return 0;
}