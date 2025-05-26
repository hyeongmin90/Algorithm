#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

vector<long long>histo;


long long solve(int left, int right) {
	if (left == right) return histo[left];
	int mid = (left + right) / 2;
	long long ans = max(solve(left, mid), solve(mid + 1,right));//분할
	int lo = mid, hi = mid + 1;//가운데 부분
	long long height = min(histo[lo], histo[hi]);
	ans = max(ans, height * 2); //분할하여 얻은 넓이와 mid, mid + 1 부분의 직사각형 넓이
	while (left < lo || hi < right) { //확장 가능할때 까지
		if (hi < right && (left == lo || histo[lo - 1] < histo[hi + 1])) {//오른쪽 확장 가능 and (왼쪽이 확장불가 or 오른쪽이 더클때)
			++hi;//오른쪽 확장
			height = min(height, histo[hi]); //확장된 구역에서의 가장 낮은 높이
		}
		else {
			--lo;
			height = min(height, histo[lo]);
		}
		ans = max(ans, height * (hi - lo + 1));
	}
	return ans;
}
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	while (1) {
		histo.clear();
		int n, num;
		cin >> n;
		if (n == 0) break;
		for (int i = 0; i < n; i++) {
			cin >> num;
			histo.push_back(num);
		}
		cout << solve(0, n - 1) << '\n';
	}
	return 0;
}