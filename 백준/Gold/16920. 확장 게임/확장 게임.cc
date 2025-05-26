#include <iostream>
#include <algorithm>
#include <queue>
#include <tuple>

using namespace std;
int n, m, p;
char board[1001][1001];
pair<int, int> dist[1001][1001];
int s[10];//플레이어 별 확장 최대 칸수
int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 };
queue<pair<int, int>> Q[10];//플레이어마다 큐 지정
bool check[10];
bool check2 = true;
int cnt[10];

int bfs(int num) {
	auto cur = Q[num].front();
	int W = dist[cur.first][cur.second].second; //초기 거리값 저장
	while (!Q[num].empty()) {
		auto cur = Q[num].front();//플레이어별 큐 블러오기
		if (dist[cur.first][cur.second].second % s[num] == 0 && dist[cur.first][cur.second].second != W) {//초기 값이 아니고 플레이어 최대 확장시 종료
			return 0;
		}
		Q[num].pop();
		for (int i = 0; i < 4; i++) {
			int nx = cur.first + dx[i];
			int ny = cur.second + dy[i];
			if (nx < 0 || ny < 0 || nx >= n || ny >= m)continue;//OOB 확인
			if (dist[nx][ny].first > 0 || board[nx][ny] == '#')continue;//벽, 방문 확인
			dist[nx][ny].first = num;//플레이어 넘버 저장(방문 표시)
			dist[nx][ny].second = dist[cur.first][cur.second].second + 1;//거리 저장
			Q[num].push({ nx,ny });
			cnt[num]++;//플레이어 성의 갯수
		}
	}
	check[num] = true;
    return 0;
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	cin >> n >> m >> p;
	for (int i = 1; i <= p; i++) {
		cin >> s[i];
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> board[i][j];
			int num = board[i][j] - '0';
			if (num >= 1 && num <= 9) {
				Q[num].push({ i,j });
				dist[i][j].first = num;
				cnt[num]++;
			}
		}
	}
	int player = 1;
	while (check2) {
		if(!check[player]) bfs(player);//player 번 플레이어 턴
		player++;
		if (player > p)player = player % p;
		check2 = false;
		for (int i = 1; i <= p; i++) {
			if (!check[i])check2 = true;
		}
	}
	for (int i = 1; i <= p; i++) cout << cnt[i] << " ";
	return 0;
}