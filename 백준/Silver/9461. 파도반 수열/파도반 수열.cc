#include <iostream>

using namespace std;

long long arr[101];
int main()
{
	arr[1] = 1;
	arr[2] = 1;
	arr[3] = 1;
	arr[4] = 2;
	arr[5] = 2;
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		int a;
		cin >> a;
		for (int j = 6; j <= a; j++) {
			if (arr[j] != 0) continue;
			arr[j] = arr[j - 1] + arr[j - 5];
		}
		cout << arr[a]<<'\n';
	}
	return 0;
}