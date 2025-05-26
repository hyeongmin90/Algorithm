#include <iostream>
#include <algorithm>

using namespace std;
int dp[1025][1025];
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	int n, m;
	cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> dp[i][j];
            dp[i][j] += dp[i - 1][j] + dp[i][j - 1] - dp[i - 1][j - 1];
        }
    }
    int x1, y1;
    int x2, y2;
    for (int i = 0; i < m; i++) {
        cin >> x1 >> y1 >> x2 >> y2;
        cout << dp[x2][y2] - dp[x2][y1 - 1] - dp[x1 - 1][y2] + dp[x1 - 1][y1 - 1] << '\n';
    }
	return 0;
}