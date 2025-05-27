#include <bits/stdc++.h>

using namespace std;

int n, w;
int dp[1002][31];
int arr[1002];


int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    cin >> n >> w;
    for (int i = 1; i <= n; i++){
        cin >> arr[i];
    }
    //움직이지 않을 경우
    for (int i = 1; i <= n; i++)
        dp[i][0] = dp[i - 1][0] + (arr[i] == 1 ? 1 : 0);
    //움직일 경우
    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= w; j++){
            if(j > i)break;
            dp[i][j] = max(dp[i - 1][j - 1], dp[i - 1][j]) + (arr[i] == 1 + j % 2 ? 1 : 0);
        }
    }
    int ans = *max_element(dp[n], dp[n] + w + 1);
    cout << ans;
    return 0;
}