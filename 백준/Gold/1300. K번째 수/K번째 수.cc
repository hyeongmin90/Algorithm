#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
long long n, k;

long long count(long long a) {
	long long sum = 0;
	for (int i = 1; i <= n; i++) {
		sum += min(n, a / i);
	}
	return sum;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	cin >> n >> k;
	long long high = n * n;
	long long low = 1;
	long long mid;
	while (low <= high) {
		mid = (high + low) / 2;
		if (count(mid) >= k) {
			high = mid - 1;
		}
		else low = mid + 1;
	}
	cout << low;
	return 0;
}