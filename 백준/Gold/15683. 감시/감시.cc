#include <iostream>
#include <algorithm>
#include <vector>
#include <tuple>
#include <string.h>
#define X first
#define Y second

using namespace std;

int n, m;
pair<int,int> board[10][10];
int arr[10][10];
vector<pair<int, int>>v;
bool check[10][10];
int dx[4] = { 1,0,-1,0 };  //아래 오른쪽 위 왼쪽 순
int dy[4] = { 0,1,0,-1 };
int ans = 100;

bool OOB(int x, int y) {
	if (x < 0 || x >= n || y < 0 || y >= m)return true;
	return false;
}

void func() {//방향값에 따른 감시범위
	memset(arr, 0, sizeof(arr));
	for (int i = 0; i < v.size(); i++) {//모든 cctv 감시 영역 탐색
		int dd[4] = { 1,0,0,0 };//방향
		int x, y;
		tie(x, y) = v[i];
		int k = board[x][y].X;//cctv 유형
		int dir = board[x][y].Y;//cctv 방향
		if (k == 2) dd[2] = 1;
		if (k == 3) dd[1] = 1;
		if (k == 4) { dd[1] = 1; dd[3] = 1; }
		if (k == 5) { dd[1] = 1; dd[2] = 1; dd[3] = 1; }
		arr[x][y] += 1;//cctv 위치
		for (int j = 0; j < 4;j++) {//cctv 유형에 따른 감시 범위
			if (dd[j] == 0)continue;
			int x1 = x, y1 = y;
			while (1)
			{
				x1 += dx[(j + dir) % 4];
				y1 += dy[(j + dir) % 4];
				if (OOB(x1, y1) || board[x1][y1].X == 6)break;//벽이나 범위 밖이면 종료
				arr[x1][y1] = 1;
			}
		}
	}
}

void dfs(int depth) {//모든 방향 둘러보기
	int cnt = 0;
	if (depth == v.size()) {
		func();
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (arr[i][j] == 0 && board[i][j].X != 6)cnt++;		
			}
		}

		ans = min(ans, cnt);
		return;
	}
	for (int i = 0; i < 4; i++) {
		board[v[depth].X][v[depth].Y].Y = (board[v[depth].X][v[depth].Y].Y + 1) % 4;//cctv 방향 돌리기
		dfs(depth + 1);
	}
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> board[i][j].X;
			if (board[i][j].X != 6 && board[i][j].X >= 1) {
				v.push_back({ i,j });
			}
		}
	}
	dfs(0);
	cout << ans;


	return 0;
}