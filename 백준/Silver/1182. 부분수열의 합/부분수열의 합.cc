#include <iostream>
#include <algorithm>

using namespace std;

int n, s;
int arr[22];
int cnt;


void func(int num, int a) {
	if (num == n) {
		if (a == s) {
			cnt++;
		}
		return;
	}
	func(num + 1, a);
	func(num + 1, a + arr[num]);
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	cin >> n >> s;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	func(0,0);
	if (s == 0)cnt--;
	cout << cnt;
	return 0;
}