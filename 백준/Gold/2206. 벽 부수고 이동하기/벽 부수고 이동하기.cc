#include <iostream>
#include <queue>
#include <algorithm>
#include <tuple>

using namespace std;

int n, m;
int board[1001][1001];
int dist[1005][1005][2];
int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 };

queue<tuple<int, int, int>>q;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		string temp;
		cin >> temp;
		for (int j = 0; j < m; j++) {
			if (temp[j] == '1')board[i][j] = -1;
			else board[i][j] = 0;
		}
	}
	
	dist[0][0][0] = dist[0][0][1] = 1;
	q.push({ 0,0,0 });
	while (!q.empty()) {
		int x, y, wall;
		tie(x,y,wall) = q.front();
		q.pop();
		if (x == n - 1 && y == m - 1) {
			cout << dist[x][y][wall];
			return 0;
		}
		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (nx < 0 || ny < 0 || nx >= n || ny >= m)continue;//행렬 밖일경우
			if (board[nx][ny] != -1 && dist[nx][ny][wall] == 0) {//벽이 아니거나 방문한적 없으면
				q.push({ nx,ny,wall });			
				dist[nx][ny][wall] = dist[x][y][wall] + 1;
			}
			if (!wall && board[nx][ny] == -1 && dist[nx][ny][wall] == 0) {//벽을 뚫은적이 없고 벽이고 방문한적 없으면
				q.push({ nx,ny,1 });
				dist[nx][ny][1] = dist[x][y][0] + 1;
			}
		}
	}
	cout << -1;
	return 0;
}