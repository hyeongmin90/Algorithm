#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>

#define X first
#define Y second

using namespace std;
int n, m; 
string board[1502];

queue<pair<int, int>>w;//물
queue<pair<int, int>>edge;//얼음의 가장자리
queue<pair<int, int>>nxt;
queue<pair<int, int>>q;
pair<int, int>swan;

int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 };
bool check;
int cnt;
bool visit[1502][1502];
bool vis[1502][1502];

void findedge() {
	while (!w.empty()) {
		auto cur = w.front();
		w.pop();
		for (int i = 0; i < 4; i++) {
			int nx = cur.X + dx[i];
			int ny = cur.Y + dy[i];
			if (nx < 0 || ny < 0 || nx >= n || ny >= m)continue;
			if (visit[nx][ny])continue;
			visit[nx][ny] = true;
			if (board[nx][ny] == 'X') {
				edge.push({ nx,ny });
			}
			
		}
	}
}

void melting() {
	while (!edge.empty()) {
		auto cur = edge.front();
		edge.pop();
		board[cur.X][cur.Y] = '.';//녹이기
		w.push(cur);
	}
}

void swanmove() {
	while (!q.empty()) {
		auto cur = q.front();
		q.pop();
		for (int i = 0; i < 4; i++) {
			int nx = cur.X + dx[i];
			int ny = cur.Y + dy[i];
			if (nx < 0 || ny < 0 || nx >= n || ny >= m)continue;
			if (vis[nx][ny])continue;//이미 방문
			if (board[nx][ny] == 'X') {//얼음
				nxt.push({ nx,ny });
				vis[nx][ny] = true;
				continue;
			}
			if (board[nx][ny] == 'L') {//백조 만남
				check = true;
				return;
			}
			q.push({ nx,ny });
			vis[nx][ny] = true;
		}
	}
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		cin >> board[i];
		for (int j = 0; j < m; j++) {
			if (board[i][j] != 'X') {
				w.push({ i,j });
			}
			if (board[i][j] == 'L') {
				swan = { i,j };

			}
		}
	}
	board[swan.X][swan.Y] = '.';
	vis[swan.X][swan.Y] = true;
	q.push({ swan.X,swan.Y });
	while(1){
		swanmove();
		if (check)break;
		findedge();
		melting();
		cnt++;//시간
		while (!nxt.empty()) {
			auto tmp = nxt.front();
			nxt.pop();
			q.push(tmp);
		}
	}
	cout << cnt;
	return 0;
}