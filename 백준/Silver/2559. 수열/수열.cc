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
	vector<int>sum(n + 1);
	vector<int>ans;
    sum[0] = 0;
	for (int i = 1; i <= n; i++) {
		int num;
		cin >> num;
		sum[i] = sum[i - 1] + num;
	}
	for (int i = 0; i < n - (m - 1); i++) {
		ans.push_back(sum[m + i] - sum[i]);
	}
	cout<< *max_element(ans.begin(), ans.end());
	return 0;
}