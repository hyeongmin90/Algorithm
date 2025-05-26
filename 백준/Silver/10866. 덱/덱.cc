#include <iostream>
#include <algorithm>
#include <deque>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int t;
	deque<int>d;
	cin >> t;
	while (t--) {
		string a;
		int x;
		cin >> a;
		if (a == "push_front") {
			cin >> x;
			d.push_front(x);
		}
		if (a == "push_back") {
			cin >> x;
			d.push_back(x);
		}
		if (a == "pop_front") {
			if (d.empty()) cout << "-1\n";
			else {
				cout << d.front() << '\n';
				d.pop_front();
			}
		}
		if (a == "pop_back") {
			if (d.empty()) cout << "-1\n";
			else {
				cout << d.back() << '\n';
				d.pop_back();
			}
		}
		if (a == "size")cout << d.size() << '\n';
		if (a == "empty")cout << d.empty() << '\n';
		if (a == "front") {
			if (d.empty()) cout << "-1\n";
			else cout << d.front() << '\n';
		}
		if (a == "back") {
			if (d.empty()) cout << "-1\n";
			else cout << d.back() << '\n';
		}
	}
	return 0;
}