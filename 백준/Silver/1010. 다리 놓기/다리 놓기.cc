#include <iostream>
#include <vector>
#include <algorithm>

long long dp[31][31];
using namespace std;

int main()
{
	int T;
	cin >> T;
	for (int i = 0; i < T; i++) {
		int N, K;
		cin >> K >> N;
		
		for (int i = 1; i <= N; i++) {
			for (int j = 0; j <= K; j++) {
				if (i == j || j == 0) {
					dp[i][j] = 1;
					continue;
				}
				dp[i][j] = (dp[i - 1][j] + dp[i - 1][j - 1]);
			}
		}
		cout << dp[N][K] <<'\n';
	}
	return 0;
}