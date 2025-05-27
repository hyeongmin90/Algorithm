#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;
bool node[1001][1001];
bool visited[1001];
int n, m, v;
queue<int>q;
void dfs(int dot) {
	cout << dot << " ";
	for (int i = 1; i <= n; i++) {
		if (!visited[i] && node[dot][i]) {
			visited[i] = true;
			dfs(i);
		}
	}
}
void bfs(int dot) {
	q.push(dot);
	while (!q.empty()) {
		dot = q.front();
		q.pop();
		cout << dot<<" ";
		for (int i = 1; i <= n; i++) {
			if (node[dot][i] && !visited[i]) {
				q.push(i);
				visited[i] = true;
			}
		}
	}
}
int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> n >> m >> v;
	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		node[a][b] = true;
		node[b][a] = true;
	}
	visited[v] = true;
	dfs(v);
	cout << '\n';
	fill_n(visited, 1001, false);
	visited[v] = true;
	bfs(v);
	return 0;
}