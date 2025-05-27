#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
#define X first
#define Y second
using namespace std;
int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 };
bool vis[101][101];
int n, m, k;
int paper[101][101];
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	vector<int>v;
	cin >> m >> n >> k;
	while (k--) {
		int x1, y1, x2, y2;
		cin >> x1 >> y1 >> x2 >> y2;
		for (int i = x1; i < x2; i++) {
			for (int j = y1; j < y2; j++) {
				paper[j][i] = 1;
			}
		}
	}
	int mx = 0;
	int num = 0;
	queue<pair<int, int>>q;
	for (int i = 0; i < m; i++) {//세로
		for (int j = 0; j < n; j++) {//가로
			if (paper[i][j] == 1 || vis[i][j])continue;
			q.push({ i,j });
			vis[i][j] = 1;
			while (!q.empty()) {
				mx++;
				auto cur = q.front(); q.pop();
				for (int u = 0; u < 4; u++) {
					int nx = cur.X + dx[u];
					int ny = cur.Y + dy[u];
					if (nx < 0 || ny < 0 || nx >= m || ny >= n)continue;
					if (paper[nx][ny] == 1 || vis[nx][ny]) continue;
					q.push({ nx,ny });
					vis[nx][ny] = 1;
				}
			}
			num++;
			v.push_back(mx);
			mx = 0;
		}
	
	}
	sort(v.begin(), v.end());
	cout << num << '\n';
	for (int i : v)cout << i << " ";
	return 0;
}