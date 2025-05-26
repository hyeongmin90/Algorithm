#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	int n, m;
	int i, j, k;
	cin >> n >> m;
	int arr[101] = {};
	for (int u = 0; u < m; u++) {
		cin >> i >> j >> k;
		for (int h = i; h <= j; h++) {
			arr[h] = k;
		}
	}
	for (int i = 1; i <= n; i++) cout << arr[i] << " ";
}