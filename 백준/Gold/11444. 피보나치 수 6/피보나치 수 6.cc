#include <iostream>
using namespace std;

long long n, b;
long long arr[5][5];
long long result[5][5];
long long temp[5][5];

void solved(long long v1[5][5], long long v2[5][5]) {

	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++) {
			temp[i][j] = 0;
			for (int k = 0; k < n; k++)
				temp[i][j] += (v1[i][k] * v2[k][j]);
			temp[i][j] %= 1000000007;
		}

	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			v1[i][j] = temp[i][j];
}
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	cin >> b;
	n = 2;
	arr[0][0] = arr[0][1] = arr[1][0] = 1LL;
	result[0][0] = result[1][1] = 1LL;
	while (b) {
		if (b % 2 == 1) {
			solved(result, arr);
		}
		solved(arr, arr);
		b /= 2;
	}
	cout << result[0][1];
	return 0;
}