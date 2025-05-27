#include <iostream>
#include <algorithm>

using namespace std;

char board[3100][6200];
int n;

void makestar(int x, int y) {//별 채우기
	board[x][y] = '*';
	board[x + 1][y + 1] = '*';
	board[x + 1][y - 1] = '*';
	for (int i = y - 2; i <= y + 2; i++) {
		board[x + 2][i] = '*';
	}
}


void star(int n, int x, int y) {
	if (n == 3) {
		makestar(x, y);
		return;
	}
	int nn = n / 2;

	//삼각형 꼭지점
	star(nn, x, y);
	star(nn, x + nn, y + nn);
	star(nn, x + nn, y - nn);
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	cin >> n;
	star(n, 0, n - 1);
	for (int i = 0; i <= n; i++) {
		for (int j = 0; j < 2 * n; j++) {
			if (board[i][j] == '*') cout << '*';
			else cout << ' ';
		}
		cout << '\n';
	}
	return 0;
}