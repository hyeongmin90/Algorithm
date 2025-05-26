#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int main()
{
	int dp[301];
	int t;
	cin >> t;
	int V[301];
	for (int i = 1; i <= t; i++) {
		cin >> V[i];
	}
	dp[1] = V[1];
	dp[2] = V[1] + V[2];
	dp[3] = max(V[1] + V[3], V[2] + V[3]);
	for (int i = 4; i <= t; i++) {
		dp[i] = max(dp[i - 2] + V[i], dp[i - 3] + V[i - 1] + V[i]);
	}
	cout << dp[t];
	return 0;
}