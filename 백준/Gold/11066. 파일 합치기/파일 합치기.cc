#include <bits/stdc++.h>

using namespace std;

int arr[501];
int dp[501][501];
int sum[501];
int INF = 0x3f3f3f3f;

int func(int left, int right){
    if(dp[left][right] != INF) return dp[left][right];
    if(left == right) return 0;
    if(left + 1 == right){
        return dp[left][right] = arr[left] + arr[right];
    }

    for(int mid = left; mid < right; mid++){
        dp[left][right] = min(dp[left][right], func(left, mid) + func(mid + 1, right));
    }
    return dp[left][right] += (sum[right] - sum[left - 1]);
}

int main(){
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        memset(dp, INF, sizeof(dp));
        for(int i = 1; i <= n; i++){
            cin >> arr[i];
            sum[i] = sum[i - 1] + arr[i];
        }
        cout << func(1, n) << '\n';
    }
}