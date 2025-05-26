#include <iostream>
#include <algorithm>
#include <queue>
#define X first
#define Y second
using namespace std;
int m, n;
queue<pair<int, int>>q;
int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 };

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	int t, k;
	cin >> t;
	while (t--) {
		int num = 0;
		int field[51][51] = {};
		bool vis[51][51] = { false };
		cin >> m >> n >> k;
		while (k--) {
			int x, y;
			cin >> x >> y;
			field[x][y] = 1; //배추 위치 세팅
		}
		for (int j = 0; j < n; j++) {
			for (int i = 0; i < m; i++) {
				if (field[i][j] != 1 || vis[i][j])continue; //배추가 없거나 방문한경우 건너뜀
				q.push({ i,j });
				while (!q.empty()) {
					auto cur = q.front();
					vis[cur.X][cur.Y] = true;
					q.pop();
					for (int u = 0; u < 4; u++) {//4방향 탐색
						int nx = cur.X + dx[u];
						int ny = cur.Y + dy[u];
						if (nx < 0 || ny < 0 || nx >= m || ny >= n)continue; //범위 밖이면 건너뜀
						if (vis[nx][ny] || field[nx][ny] != 1)continue; //방문 여부 체크 & 배추 체크
						q.push({ nx,ny });
						vis[nx][ny] = true;
					}
				}
				num++;
			}
		}
		cout << num << '\n';
	}
	return 0;
}