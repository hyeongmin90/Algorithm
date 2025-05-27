#include <iostream>
int arr[10001];
int dp[10001];
using namespace std;

int main()
{
	int t;
	cin >> t;
	for (int i = 1; i <= t; i++) {
		cin >> arr[i];
	}
	dp[1] = arr[1];
	dp[2] = arr[1] + arr[2];
	dp[3] = max(arr[1] + arr[3], arr[2] + arr[3]);
	for (int i = 4; i <= t; i++) {
		dp[i] = max(dp[i - 2] + arr[i], max(dp[i - 4],dp[i - 3]) + arr[i - 1] + arr[i]);
	}
	cout << max(dp[t], dp[t - 1]);
	
	return 0;
}