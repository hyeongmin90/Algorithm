#include <iostream>
#include <vector>
#include <algorithm>

long long dp[1001][1001];
using namespace std;

int main()
{
	int N, K;
	cin >> N >> K;
	for (int i = 1; i <= N; i++) {
		for (int j = 0; j <= K; j++) {
			if (i == j || j == 0) {
				dp[i][j] = 1;
				continue;
			}
			dp[i][j] = (dp[i - 1][j] + dp[i - 1][j - 1]) % 10007;
		}
	}
	cout << dp[N][K];
	return 0;
}