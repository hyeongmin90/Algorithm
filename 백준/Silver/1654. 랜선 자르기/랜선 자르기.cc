#include <iostream>
#include <algorithm>
using namespace std;
int arr[10001];
long long Left, Right;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	int k, m;
	long long ans = 0;
	cin >> k >> m;
	for (int i = 0; i < k; i++) {
		cin >> arr[i];
	}
	Left = 1;
	Right = *max_element(arr, arr + k);
	
	while (Left <= Right) {
		long long mid = (Right + Left) / 2;
		int num = 0;
		for (int i = 0; i < k; i++) {
			num += arr[i] / mid;
		}
		if (num >= m) {
			Left = mid + 1;
			ans = max(ans, mid);
		}
		else {
			Right = mid - 1;
		}
	}
	cout << ans;
	return 0;
}