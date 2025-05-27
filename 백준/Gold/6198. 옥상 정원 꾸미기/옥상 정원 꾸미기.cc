#include <iostream>
#include <stack>
#include <algorithm>

using namespace std;

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	stack<int>S;
	int n;
	long long ans = 0;
	cin >> n;
	while (n--) {
		int num;
		cin >> num;
		
		while (1) {
			if (S.empty()) { // 스택이 비어있으면 넣기
				S.push(num);
				break;
			}
			else {
				if (S.top() > num) { // S.top() 가 num보다 크면 S에 들어있는 수의 갯수만큼 ans 에 더한후 S에 넣기
					ans += S.size();
					S.push(num);
					break;
				}
				else {
					S.pop();//S.top() 이 num보다 클떄까지 아니면 S가 빌때까지 pop
				}
			}
		}
	}
	cout << ans;
	return 0;
}