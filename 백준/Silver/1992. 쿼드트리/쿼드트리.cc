#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int square[128][128];
int N;
void cut(int num1, int num2, int n) {
	bool check = true;
	bool check2 = true;
	for (int i = num1; i < num1 + n; i++) {
		for (int j = num2; j < num2 + n; j++) {
			if (square[i][j] != 1) check = false;
			if (square[i][j] != 0) check2 = false;
		}
	}
	if (!check && !check2) {
		cout << '(';
		n /= 2;
		cut(num1, num2, n);
		cut(num1, num2 + n, n);
		cut(num1 + n, num2, n);
		cut(num1 + n, num2 + n, n);
		cout << ')';
	}
	else {
		if (check) cout << 1;
		if (check2) cout<< 0;
	}
}
int main()
{
	cin >> N;
	vector<string>color(N);
	for (int i = 0; i < N; i++) {
		cin >> color[i];
	}
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			square[i][j] = (color[i][j] - '0');
		}
	}
	cut(0, 0, N);
	return 0;
}