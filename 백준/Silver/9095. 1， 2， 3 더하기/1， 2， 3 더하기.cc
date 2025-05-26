#include <iostream>

using namespace std;


int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	int n, t;
	int dp[12];
	cin >> t;
	dp[1] = 1;
	dp[2] = 2;
	dp[3] = 4;
	while (t--) {
		cin >> n;
		for (int i = 4; i <= n; i++) {
			dp[i] = dp[i - 1] + dp[i - 2] + dp[i - 3];
		}
		cout << dp[n] << '\n';

	}
	return 0;
}