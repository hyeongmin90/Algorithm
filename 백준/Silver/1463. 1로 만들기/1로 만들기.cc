#include <iostream>
#include <algorithm>
int dp[1000001];
using namespace std;
int main()
{
	int n;
	
	cin >> n;
	dp[1] = 0;
	dp[2] = 1;
	dp[3] = 1;
	for (int i = 4; i <= n; i++) {
		int num = 1000000;
		if (i % 3 == 0) num = min(num, dp[i / 3] + 1);
		if (i % 2 == 0) num = min(num, dp[i / 2] + 1);
		num = min(num, dp[i - 1] + 1);
		dp[i] = num;
	}
	cout << dp[n];
	return 0;
}