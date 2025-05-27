#include <iostream>
#include <algorithm>
#include <queue>
#define X first
#define Y second
using namespace std;


int paper[105][105];
int dist[105][105];
bool visited[105][105];
int n, m;
string board;
queue<pair<int, int>>coord;
int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 };
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		cin >> board;
		for (int j = 0; j < m; j++) {
			paper[i][j] = (board[j] - '0');
		}
	}
	queue<pair<int, int>>q;
	visited[0][0] = 1;//방문 표시
	q.push({ 0,0 });
	dist[0][0]++;
	while (!q.empty()) {//주변 탐색
		pair<int, int>coord = q.front();
		q.pop();
		for (int u = 0; u < 4; u++) {//상하좌우 탐색
			int nx = coord.X + dx[u];
			int ny = coord.Y + dy[u];
			if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue; //범위 밖일경우
			if (visited[nx][ny] || paper[nx][ny] == 0) continue; // 0이거나 이미 방문했을경우
			visited[nx][ny] = 1;//방문 표시
			q.push({ nx,ny });
			dist[nx][ny] = dist[coord.X][coord.Y] + 1;
		}	
    }
	cout << dist[n - 1][m - 1];
	return 0;
}