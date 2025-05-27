#include <iostream>
#include <algorithm>
#include <stack>
#include <vector>
using namespace std;

int main()
{
	stack<int>stk;
	stk.push(0);
	int n;
	cin >> n;
	int num, cnt = 1;

	vector<char>ans;
	for (int i = 0; i < n; i++) {
		cin >> num;
		while (stk.top() < num) {
			stk.push(cnt);
			cnt++;
			ans.push_back('+');
		}
		if (stk.top() == num) {
			stk.pop();
			ans.push_back('-');
		}
		else {
			cout << "NO";
			return 0;
		}
	}
	for (int i = 0; i < ans.size(); i++) 
		cout << ans[i] << '\n';


	return 0;
}