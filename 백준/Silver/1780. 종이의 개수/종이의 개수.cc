#include <iostream>
#include <algorithm>

using namespace std;
int square[2187][2187];
int N;
int cnt[3];
bool check(int y, int x, int n) {
	int start = square[y][x];
	for (int i = y; i < y + n; i++) 
		for (int j = x; j < x + n; j++) 
			if (square[i][j] != start) return false;
	return true;
}
void cut(int y, int x, int n) {
	int start = square[y][x];
	if (!check(y, x, n)) {
		n /= 3;
		for (int i = 0; i < 3;i++){
			cut(y, x + i * n, n);
			cut(y + n, x + i * n, n);
			cut(y + 2 * n, x + i * n, n);
		}
	}
	else cnt[start]++;
	
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> N;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			int input;
			cin >> input;
			square[i][j] = input + 1;
		}
	}
	cut(0, 0, N);
	for (int i = 0; i < 3; i++) cout << cnt[i] << '\n';
	return 0;
}