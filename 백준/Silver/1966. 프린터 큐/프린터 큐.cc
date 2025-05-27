#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

int main()
{
	int t;
	cin >> t;
	while (t--) {
		int cnt = 0;
		queue<pair<int,int>>q;
		priority_queue<int>Q;
		int n, m;
		cin >> n >> m;
		for (int i = 0; i < n; i++) {
			int num;
			cin >> num;
			q.push({ num,i });
			Q.push(num);
		}
		while (!q.empty()) {
			if (q.front().first == Q.top()) {
				cnt++;
				if (q.front().second == m) {
					cout << cnt << '\n';
					break;
				}
				q.pop();
				Q.pop();
			}
			else {
				q.push(q.front());
				q.pop();
			}
		}
	}
	return 0;
}