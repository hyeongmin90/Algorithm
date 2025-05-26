#include <iostream>
#include <algorithm>
#include <queue>

#define X first
#define Y second
using namespace std;
int n;
queue<pair<int, int>>q;
int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 };
char boardN[101][101]; 
char boardR[101][101];

int bfs(char board[][101]) {
	int ans = 0;
	bool vis[101][101] = { false };
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (vis[i][j]) continue;
			vis[i][j] = true;
			q.push({ i,j });
			char a = board[i][j];
			while (!q.empty()) {
				auto cur = q.front(); q.pop();
				for (int u = 0; u < 4; u++) {
					int nx = cur.X + dx[u];
					int ny = cur.Y + dy[u];
					if (nx < 0 || ny < 0 || nx >= n || ny >= n)continue;
					if (vis[nx][ny] || board[nx][ny] != a) continue;
					q.push({ nx,ny });
					vis[nx][ny] = true;
				}
			}
			ans++;
		}
	}
	return ans;
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	cin >> n;
	for (int i = 0; i < n; i++) {
		string temp;
		cin >> temp;
		for (int j = 0; j < n; j++) {
			boardN[i][j] = temp[j];
			if (temp[j] == 'G') boardR[i][j] = 'R';
			else boardR[i][j] = temp[j];
		}
	}
	cout << bfs(boardN) << " " << bfs(boardR);
	return 0;
}