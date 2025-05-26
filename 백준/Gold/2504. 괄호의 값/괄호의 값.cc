#include <iostream>
#include <stack>
#include <algorithm>

using namespace std;

int main() {
	int n;
	int sum = 0;
	int num = 1;
	string s;
	stack<char>stk;
    cin >> s;
	for (int i = 0; i < s.length(); i++) {
		if (s[i] == '(') {
			num *= 2;
			stk.push(s[i]);
		}
		else if (s[i] == '[') {
			num *= 3;
			stk.push(s[i]);
		}
		else if (s[i] == ')') {
			if (stk.empty() || stk.top() != '(') {
				cout << 0;
				return 0;
			}
			if (s[i - 1] == '(') sum += num;
			stk.pop();
			num /= 2;
		}
		else if (s[i] == ']') {
			if (stk.empty() || stk.top() != '[') {
				cout << 0;
				return 0;
			}
			if (s[i - 1] == '[') sum += num;
			stk.pop();
			num /= 3;
		}
	}
	if (stk.empty())cout << sum;
	else cout << 0;
	return 0;
}