#include <iostream>
#include <algorithm>
#include <deque>
using namespace std;

int main()
{
	int n, m;
	int cnt = 0;
	deque<int>d;
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		d.push_back(i);
	}
	for (int i = 0; i < m; i++) {
		int num;
		cin >> num;
		int order;
		for (int i = 0; i < n; i++) {
			if (d[i] == num) {
				order = i;
				break;
			}
		}
		while (1) {
			if (d.front() == num) {
				d.pop_front();
				break;
			}
			if (d.size() - order > order) {
				d.push_back(d.front());
				d.pop_front();
				cnt++;
			}
			else {
				d.push_front(d.back());
				d.pop_back();
				cnt++;
			}
		}
	}
	cout << cnt;
	return 0;
}