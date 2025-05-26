#include <iostream>

using namespace std;
int cnt1 = 0, cnt2 = 0;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	int n, t;
	int dp[41];
	cin >> t;
	dp[0] = 1;
	dp[1] = 0;
	dp[2] = 1;
	dp[3] = 1;
	while (t--) {
		cin >> n;
		n += 2;
		for (int i = 4; i <= n; i++) {
			dp[i] = dp[i - 1] + dp[i - 2];
		}
		cout << dp[n - 2] << " " << dp[n - 1] << '\n';

	}
	return 0;
}