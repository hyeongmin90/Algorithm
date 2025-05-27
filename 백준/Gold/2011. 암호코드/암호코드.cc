#include <bits/stdc++.h>

using namespace std;

int arr[5002];
int dp[5002];
int mod = 1000000;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    string num;
    cin >> num;
    int n = num.length();
    for (int i = 1; i <= n; i++)
        arr[i] = num[i - 1] - '0';

    dp[0] = 1;

    for (int i = 1; i <= n; i++){
        if(arr[i] > 0)
            dp[i] = (dp[i] + dp[i - 1]) % mod;
        int m = arr[i - 1] * 10 + arr[i];
        if(m >= 10 && m <= 26)
            dp[i] = (dp[i] + dp[i - 2]) % mod;
    }
    cout << dp[n];

    return 0;
}