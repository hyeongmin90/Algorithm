#include <iostream>
#include <algorithm>
#include <stack>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n;
	stack<int>s;
	cin >> n;
	for (int i = 0; i < n; i++) {
		string A;
		int x;
		cin >> A;
		if (A == "push") {
			cin >> x;
			s.push(x);
		}
		if (A == "pop") {
			if (s.empty()) cout << -1 << '\n';
			else {
				cout << s.top() << '\n';
				s.pop();
			}
		}
		if (A == "size") {
			cout << s.size() << '\n';
		}
		if (A == "empty") {
			cout << s.empty() << '\n';
		}
		if (A == "top") {
			if (s.empty()) cout << -1 << '\n';
			else cout << s.top() << '\n';
		}

	}
	return 0;
}