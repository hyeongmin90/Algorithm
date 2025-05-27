#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main()
{
	int n;
	cin >> n;
	vector<pair<int, int>>meeting;
	for (int i = 0; i < n; i++) {
		int a, b;
		cin >> a >> b;
		meeting.push_back(make_pair(b,a));
	}
	sort(meeting.begin() , meeting.end());
	int  f = meeting[0].first;
	int cnt = 1;
	for (int i = 1; i < n; i++) {
		if (meeting[i].second < f) continue;
		f = meeting[i].first;
		cnt++;
	}
	cout << cnt;
	return 0;
}