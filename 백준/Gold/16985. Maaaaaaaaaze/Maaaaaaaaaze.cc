#include <iostream>
#include <algorithm>
#include <queue>
#include <tuple>
#define X first
#define Y second

using namespace std;

int board[7][7][7];
int brute[5] = { 0,1,2,3,4 };
int board2[7][7][7];
queue<tuple<int, int, int>>q;
int dx[6] = { 1,0,-1,0,0,0 };
int dy[6] = { 0,1,0,-1,0,0 };
int dz[6] = { 0,0,0,0,-1,1 };
int ans = 0x7f7f7f7f;

bool OOB(int x, int y, int z) {
	if (x < 0 || x >= 5 || y < 0 || y >= 5 || z < 0 || z >= 5) return true;
	return false;
}


void maze() {
	bool visit[7][7][7] = { false };
	int dist[7][7][7] = {};
	if (board2[0][0][0] == 0 || board2[4][4][4] == 0)return;
	q.push({ 0,0,0 });
	visit[0][0][0] = true;
	while (!q.empty()) {
		int x, y, z;
		tie(z,x,y) = q.front();
		q.pop();
		if (z == 4 && x == 4 && y == 4) {
			ans = min(ans, dist[z][x][y]);
			
		}
		for (int i = 0; i < 6; i++) {
			int nz = z + dz[i];
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (OOB(nx, ny, nz) || visit[nz][nx][ny] || board2[nz][nx][ny] == 0)continue;
			q.push({ nz,nx,ny });
			visit[nz][nx][ny] = true;
			dist[nz][nx][ny] = dist[z][x][y] + 1;
		}
	}
}



void turn(int num, int dir) {//num 번째 판을 dir번 돌리기
	int tmp[7][7];
	for (int k = 0; k < dir; k++) {//dir 만큼 돌리기
		for (int i = 0; i < 5; i++) {
			for (int j = 0; j < 5; j++) {
				tmp[i][j] = board2[num][i][j];
			}
		}
		for (int i = 0; i < 5; i++) {
			for (int j = 0; j < 5; j++) {
				board2[num][i][j] = tmp[4 - j][i];
			}
		}
	}
}


int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	for (int t = 0; t < 5; t++) {
		for (int i = 0; i < 5; i++) {
			for (int j = 0; j < 5; j++) {
				cin >> board[t][i][j];
			}
		}
	}

	do {
		for (int tmp = 0; tmp < 1024; tmp++) {//판 돌리기
			//판 쌓기
			for (int t = 0; t < 5; t++) {
				for (int i = 0; i < 5; i++) {
					for (int j = 0; j < 5; j++) {
						board2[t][i][j] = board[brute[t]][i][j];
					}
				}
			}
			//미로 돌리기
			int brut = tmp;
			for (int i = 0; i < 5; i++) {
				int dir = brut % 4; //돌리는 횟수
				brut /= 4;
				turn(i, dir);
			}
			//미로 경로 탐색
			maze();
		}
	} while (next_permutation(brute, brute + 5));//판을 쌓는 순서

	if (ans == 0x7f7f7f7f)ans = -1;
	cout << ans;


	

	return 0;
}