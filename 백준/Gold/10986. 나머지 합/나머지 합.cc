#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	int n, m;
	cin >> n >> m;
	vector<int>dp(n + 1);
	vector<int>cnt(m);
	for (int i = 1; i <= n; i++) {
		int num;
		cin >> num;
		dp[i] = (dp[i - 1] + num) % m;
		cnt[dp[i]]++;
	}
	long long ans = cnt[0];
	for (int i = 0; i < m; i++) {
		ans += 1LL * cnt[i] * (cnt[i] - 1) / 2;
	}
	cout << ans;
	return 0;
}