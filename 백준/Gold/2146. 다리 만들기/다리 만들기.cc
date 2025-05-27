#include <iostream>
#include <queue>
#include <algorithm>

#define X first
#define Y second
using namespace std;

int n;
int ans = 1000;
pair<int,int> map[101][101];
bool visit[101][101];
int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 };
bool check;
queue<pair<int,int>>q;
queue<pair<int, int>>Q;
void bridge() {//해안가에서 부터 다리시작
	while (!Q.empty()) {
		auto cur = Q.front(); Q.pop();//해안가 //해안가와 섬들은 이미 방문처리 되어있음
		for (int i = 0; i < 4; i++) {
			int nx = cur.X + dx[i];
			int ny = cur.Y + dy[i];
			if (nx < 0 || ny < 0 || nx >= n || ny >= n)continue; //범위 밖 처리
			if (map[nx][ny].Y == map[cur.X][cur.Y].Y) continue; //같은섬에서 출발한 점과 만남
			if (map[nx][ny].Y == 0) {//바다
				Q.push({ nx,ny });
				visit[nx][ny] = true;
				map[nx][ny] = { map[cur.X][cur.Y].X + 1,map[cur.X][cur.Y].Y };
			}
			else {//다른 섬에서 출발한 점과 만남
				ans = min(ans, map[cur.X][cur.Y].X + map[nx][ny].X);
			}
		}
	}
	cout << ans;
}
void setting() {//섬에 넘버링과 해안가 판별
	int island = 1;//각각의 섬 넘버링
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (map[i][j].X != 1 || visit[i][j])continue;//바다거나 이미 방문했다면 건너뜀
			q.push({ i,j });
			visit[i][j] = true;
			map[i][j].Y = island;
			while (!q.empty()){
				auto cur = q.front(); q.pop();
				for (int u = 0; u < 4; u++) {
					int nx = cur.X + dx[u];
					int ny = cur.Y + dy[u];
					if (nx < 0 || ny < 0 || nx >= n || ny >= n)continue; //범위 밖 처리
					if (map[nx][ny].Y != 0 && map[nx][ny].Y != map[cur.X][cur.Y].Y) {//다른 섬에서 출발한 점과 만남 //섬과 섬이 한칸 떨어짐
						cout << map[cur.X][cur.Y].X << '\n';
						map[nx][ny].X = -1;
						check = true;
							return;
					}
					if (visit[nx][ny])continue; //방문체크
					if (map[nx][ny].X == 0) {//해안가 세팅
						map[nx][ny] = { 1,island };
						Q.push({ nx,ny });
						visit[nx][ny] = true;
					}
					else {//섬
						visit[nx][ny] = true;
						map[nx][ny].Y = island;
						q.push({ nx,ny });
					}
				}
			}
			island++;
		}
	}
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> map[i][j].X;
		}
	}
	setting();
	if(!check)bridge();
	return 0;
}