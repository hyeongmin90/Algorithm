#include <iostream>
#include <algorithm>

using namespace std;
int n, m;
int arr[10];
int ans[10];

void func(int depth, int num) {
	if (depth == m) {
		for (int i = 0; i < m; i++) {
			cout << ans[i] << " ";
		}
		cout << '\n';
		return;
	}
	for (int i = num; i < n; i++) {
		ans[depth] = arr[i];
		func(depth + 1,i);
	}
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	sort(arr, arr + n);
	func(0,0);
	return 0;
}