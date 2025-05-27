#include <iostream>
#include <stack>
#include <algorithm>

using namespace std;

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	stack<pair<int,int>>S1;
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		int num;
		cin >> num;
		while (!S1.empty()) {
			if (S1.top().first > num) {
				cout << S1.top().second << " ";
				S1.push({num,i});
				break;
			}
			else {
				S1.pop();
			}
		}
		if (S1.empty()) {
			cout << 0 << " ";
			S1.push({ num,i});
		}
	}
	return 0;
}