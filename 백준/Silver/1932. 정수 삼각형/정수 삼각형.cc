#include <iostream>
#include <algorithm>

using namespace std;
int triangle[501][500];
int main()
{
	
	int t;
	cin >> t;
	for (int i = 1; i <= t; i++) {
		for (int j = 0; j < i; j++) {
			cin >> triangle[i][j];
		}
	}
	for (int i = t; i >= 0; i--) {
		for (int j = 0; j < i ; j++) {
			triangle[i - 1][j] = max(triangle[i][j], triangle[i][j + 1]) + triangle[i - 1][j];
		}
	}
	cout << triangle[1][0];
	return 0;
}