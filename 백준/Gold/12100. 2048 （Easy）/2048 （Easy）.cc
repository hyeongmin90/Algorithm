#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
int n;
int board[22][22];
int board2[22][22];
int mx;




void rotate() {
	int tmp[22][22];
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			tmp[i][j] = board2[i][j];
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			board2[i][j] = tmp[n - 1 - j][i];
		}
	}
}

void tile(int dir) {
	while (dir--)rotate();
	for (int j = 0; j < n; j++) {
		int idx = 0;
		int num = 0;
		for (int i = 0; i < n; i++) {
			if (board2[j][i] == 0)continue;
			if (num == 0) {
				num = board2[j][i];
				board2[j][i] = 0;
				continue;
			}
			if (num == board2[j][i]) {
				board2[j][idx] = num * 2;
				idx++;
				num = 0;
			}
			else {
				board2[j][idx] = num;
				num = board2[j][i];
				idx++;
			}
			board2[j][i] = 0;
		}
		board2[j][idx] = num;
	}
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> board[i][j];
		}
	}
	for (int tmp = 0; tmp < 1024; tmp++) {
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				board2[i][j] = board[i][j];
			}
		}
		int brute = tmp;
		for (int i = 0; i < 5; i++) {
			int dir = brute % 4;
			brute /= 4;
			tile(dir);
		}
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				mx = max(mx, board2[i][j]);
			}
		}
	}
	cout << mx;


	return 0;
}