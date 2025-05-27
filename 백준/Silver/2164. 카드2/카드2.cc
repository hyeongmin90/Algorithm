#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
using namespace std;

int main()
{
	queue<int>q;
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		q.push(i);
	}
	if (n == 1) { cout << 1; return 0; }
	for (int i = 1; i <= n; i++) {
		q.pop();
		if (q.size() == 1)break;
		q.push(q.front());
		q.pop();
	}
	cout << q.front();
	return 0;
}