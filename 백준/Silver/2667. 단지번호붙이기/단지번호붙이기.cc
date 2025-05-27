#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>

using namespace std;
string board[30];
bool visit[30][30];
int n;
int dx[4] = { 1, 0, -1, 0 };
int dy[4] = { 0, 1, 0, -1 };
vector<int>v;
queue<pair<int, int>> q;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> board[i];
	}
	int area = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (visit[i][j] || board[i][j] == '0') continue;
			area++;
			q.push({ i,j });
			visit[i][j] = 1;
			int cnt = 0;
			while (!q.empty())
			{
				cnt++;
				auto cur = q.front();
				q.pop();
				for (int i = 0; i < 4; i++)
				{
					int nx = cur.first + dx[i];
					int ny = cur.second + dy[i];
					if (nx < 0 || ny < 0 || nx >= n || ny >= n) continue;
					if (visit[nx][ny] || board[nx][ny] == '0')continue;
					q.push({ nx,ny });
					visit[nx][ny] = 1;
				}
			}
			v.push_back(cnt);
		}
	}
	sort(v.begin(), v.end());
	cout << area << '\n';
	for (int i : v) cout << i << '\n';
	return 0;
}