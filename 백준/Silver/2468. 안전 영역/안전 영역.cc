#include <iostream>
#include <algorithm>
#include <queue>
#include <string.h>

using namespace std;
int n;
int board[101][101];
bool visit[101][101];
int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 };
queue<pair<int, int>>q;
bool check;
int cnt, ans;
void rain() {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (board[i][j] > 0) {
				board[i][j]--;
				check = true;
			}
		}
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
	int a = 0;
	while (1) {
		a++;
		check = false;
		memset(visit, false, sizeof(visit));
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (visit[i][j] || board[i][j] < 1)continue;
				cnt++;
				q.push({ i,j });
				visit[i][j] = true;
				while (!q.empty()) {
					auto cur = q.front(); q.pop();
					for (int k = 0; k < 4; k++) {
						int nx = cur.first + dx[k];
						int ny = cur.second + dy[k];
						if (nx < 0 || ny < 0 || nx >= n || ny >= n)continue;
						if (visit[nx][ny] || board[nx][ny] < 1)continue;
						q.push({ nx,ny });
						visit[nx][ny] = true;
					}
				}
			}
		}
		ans = max(ans, cnt);
		cnt = 0;
		rain();
		if (!check) {
			cout << ans;
			return 0;
		}
	}
	return 0;
}