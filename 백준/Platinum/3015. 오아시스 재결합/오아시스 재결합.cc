#include <iostream>
#include <stack>
#include <algorithm>

using namespace std;

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	
	int n,c=0;
	long long cnt = 0;
	stack<int>S;
	stack<int>S2;
	cin >> n;
	while (n--) {
		int num;
		cin >> num;
		while (1) {
			if (S.empty()) {
				S.push(num);
				S2.push(1);
				break;
			}
			else {
				if (S.top() >= num) {
					if (S.top() == num) {//같은 값이 연속해 입력할경우
						S.push(num);
						S2.push(S2.top() + 1);
						int temp = S2.top();
						if (S.size() == temp) temp--;
						cnt += temp;
					}
					else { //작은값 입력시
						S.push(num);
						S2.push(1);
						cnt++;
					}
				     break;
				}
				else {//큰값 입력시
					cnt++;
					S.pop();
					S2.pop();
				}
			}
		}
	}
	cout << cnt << '\n';
	
	return 0;
}