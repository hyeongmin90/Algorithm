#include <iostream>
#include <algorithm>

using namespace std;

int dp[42];
int arr[42];
int n, vip;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    dp[0] = 1;
    dp[1] = 1;
    dp[2] = 2;
    for (int i = 3; i <= 40; i++)
    {
        dp[i] = dp[i - 1] + dp[i - 2];
    }
    cin >> n >> vip;
    for (int i = 0; i < vip; i++)
        cin >> arr[i];
    sort(arr, arr + vip);
    int idx = 0;
    int ans = 1;
    for (int i = 0; i < vip; i++)
    {
        int tmp = arr[i] - idx - 1;
        ans *= dp[tmp];
        idx = arr[i];
    }
    ans *= dp[n - idx];
    cout << ans;
    return 0;
}