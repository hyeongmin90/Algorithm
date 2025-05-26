#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main()
{
	pair<int, int>arr[100];
	int t;
	cin >> t;
	vector<int>dp(t, 1);
	for (int i = 0; i < t; i++) {
		int a, b;
		cin >> a >> b;
		arr[i] = make_pair(a, b);
	}
	sort(arr, arr + t);
	for (int i = 1; i < t; i++) {
		for (int j = 0; j < i; j++) {
			if (arr[i].second > arr[j].second) dp[i] = max(dp[i], dp[j] + 1);
		}
	}
	int ans = *max_element(dp.begin(), dp.end());
	cout << t - ans;
	return 0;
}