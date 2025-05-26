#include <iostream>


long long dp[1000001];
using namespace std;
int main()
{
	int n;
	cin >> n;
	dp[1] = 1;
	dp[2] = 2;
	for (int i = 3; i <= n; i++) {
		dp[i] = (dp[i - 1] + dp[i - 2]) % 15746;
	}
	cout << dp[n];
	return 0;
}