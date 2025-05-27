#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

long long Left, Right;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	int n, c;
	long long ans = 0;
	cin >> n >> c;
	vector<int>house(n);
	for (int i = 0; i < n; i++) {
		cin >> house[i];
	}
	sort(house.begin(), house.end());
	Left = 1; 
	Right = house[n - 1] - house[0];
	
	while (Left <= Right) {
		int cnt = 1;
		long long mid = (Right + Left) / 2;
		int k = 0;
		for (int i = 1; i < n; i++) {
			if (house[i] - house[k] >= mid) {
				cnt++;
				k = i;
			}
		}
		if (cnt >= c) {
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