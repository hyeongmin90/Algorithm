#include <iostream>
#include <algorithm>

using namespace std;
int square[128][128];
int cntB, cntW;
int N;
void cut(int num1, int num2, int n) {
	bool check = true;
	bool check2 = true;
	for (int i = num1; i < num1 + n; i++) {
		for (int j = num2; j < num2 + n; j++) {
			if (square[i][j] != 1) {
				check = false;
			}
			if (square[i][j] != 0) {
				check2 = false;
			}
		}
	}
	if (!check && !check2) {
		n /= 2;
		cut(num1, num2, n);
		cut(num1 + n, num2, n);
		cut(num1, num2 + n, n);
		cut(num1 + n, num2 + n, n);
	}
	else {
		if (check) cntB++;
		if (check2) cntW++;
	}
}

int main()
{
	cin >> N;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> square[i][j];
		}
	}
	cut(0, 0, N);
	cout << cntW<<'\n'<<cntB;
	return 0;
}