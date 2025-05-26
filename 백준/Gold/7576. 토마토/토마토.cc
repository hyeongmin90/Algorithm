#include <iostream>
#include <algorithm>
#include <queue>
#define X first
#define Y second
using namespace std;


int board[1005][1005];
int n, m;
int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 };
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	cin >> m >> n;
	queue<pair<int, int>>q;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> board[i][j];
			if (board[i][j] == 1) q.push({ i,j });//시작점
		}
	}
	while (!q.empty()) {
		pair<int, int>cur = q.front();
		q.pop();
		for (int u = 0; u < 4; u++) {//상하좌우 탐색
			int nx = cur.X + dx[u];
			int ny = cur.Y + dy[u];
			if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue; //범위 밖일경우
			if (board[nx][ny] == -1 || board[nx][ny] > 0) continue; //토마토가 없거나 익은경우
			q.push({ nx,ny });
			board[nx][ny] = board[cur.X][cur.Y] + 1;//토마토가 익는데 걸린시간
		}	
    }
	int ans = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (board[i][j] == 0) {//익지 않은 토마토가 있을경우
				cout << -1;
				return 0;
			}
			ans = max(ans, board[i][j]);//가장 큰값 찾기
		}
	}
	cout << ans - 1;//시작한시간인 1 뺴기
	return 0;
}