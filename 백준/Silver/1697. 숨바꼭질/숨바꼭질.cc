#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;
queue<int>q;
int n, k;
int dist[100001];
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	cin >> n >> k;
	q.push(n);
	fill(dist, dist + 100001, -1);
	dist[n] = 0;
	while (dist[k] == -1) {
		int cur = q.front();
		q.pop();
		for (int nxt : {cur + 1, cur - 1, cur * 2}) {
			if (nxt < 0 || nxt > 100000) continue;
			if (dist[nxt] != -1) continue;
			dist[nxt] = dist[cur] + 1;
			q.push(nxt);
		}
	}
	cout << dist[k];
	return 0;
}