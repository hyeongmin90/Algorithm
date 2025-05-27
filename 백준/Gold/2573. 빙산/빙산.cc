#include <iostream>
#include <queue>
#include <algorithm>
#include <string.h>
#define X first
#define Y second
using namespace std;

int n, m;
int melt[301][301];
int ocean[301][301];
bool visit[301][301];
int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 };
int year;
int num;
queue<pair<int,int>>q;

void melting() {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			ocean[i][j] = max(0, ocean[i][j] - melt[i][j]);
		}
	}
	year++;
}
void bfs() {
	memset(visit, false , sizeof(visit));
	memset(melt, 0, sizeof(melt));
	num = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (ocean[i][j] == 0 || visit[i][j])continue;
			num++;//빙산 덩어리 갯수
			if (num > 1) {//빙산이 두덩어리 이상
				cout << year;
				return;
			}
			q.push({ i,j });
			visit[i][j] = 1;		
			while (!q.empty()) {
				int sea = 0;
				auto cur = q.front(); q.pop();
				visit[cur.X][cur.Y] = 1;//방문처리
				for (int u = 0; u < 4; u++) {
					int nx = cur.X + dx[u];
					int ny = cur.Y + dy[u];
					if (nx < 0 || ny < 0 || nx >= n || ny >= m)continue;
					if (visit[nx][ny])continue;
					if (ocean[nx][ny] == 0) sea++;//접하는 바다면
					else {
						q.push({ nx,ny });
						visit[nx][ny] = 1;//방문처리
					}
				}
				melt[cur.X][cur.Y] = sea;//접하는 바다면 저장
			}
		}
	}
	if (num == 0) {//빙산 없음
		cout << 0;
		return;
	}
	else{ //num = 1 빙산존재 & 빙산 한덩어리
		melting();//녹이기
		bfs();//다시 실행
	}
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> ocean[i][j];
		}
	}
	bfs();
	return 0;
}