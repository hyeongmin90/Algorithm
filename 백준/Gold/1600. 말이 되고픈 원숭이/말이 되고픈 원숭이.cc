#include <iostream>
#include <queue>
#include <algorithm>
#include <tuple>

using namespace std;

int K, n, m;//n 세로 m 가로
int board[201][201];
int dist[201][201][30];

queue<tuple<int, int, int>>q;
int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 };
int Dx[8] = { 1,2,2,1,-1,-2,-2,-1 };
int Dy[8] = { 2,1,-1,-2,-2,-1,1,2 };
bool OOB(int a, int b) {//범위 밖
	if (a < 0 || b < 0 || a >= n || b >= m) return true;
	return false;
}

void bfs() {
	q.push({ 0,0,0 });
	while (!q.empty()) {
		int x, y, k;
		tie(x, y, k) = q.front();
		q.pop();
		if (x == n - 1 && y == m - 1) {
			cout << dist[x][y][k];
			return;
		}
		for (int i = 0; i < 4; i++) {//상하좌우 4방향
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (OOB(nx, ny))continue;
			if (board[nx][ny] || dist[nx][ny][k] != 0)continue;
			q.push({ nx,ny,k });
			dist[nx][ny][k] = dist[x][y][k] + 1;
		}
		if (k < K) {//말처럼 이동 가능 횟수가 남아있다면
			for (int i = 0; i < 8; i++) {
				int nx = x + Dx[i];
				int ny = y + Dy[i];
				if (OOB(nx, ny))continue;
				if (board[nx][ny] || dist[nx][ny][k + 1] != 0)continue;
				q.push({ nx,ny,k + 1 });
				dist[nx][ny][k + 1] = dist[x][y][k] + 1;
			}
		}
	}
	cout << -1;
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	cin >> K >> m >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin>>board[i][j];
		}
	}
	bfs();
	return 0;
}