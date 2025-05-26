#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;



int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	int n, m;
	cin >> n;
	vector<int>V1(n);
	for (int i = 0; i < n; i++) {
		cin >> V1[i];
	}
	sort(V1.begin(), V1.end());
	cin >> m;
	for (int i = 0; i < m; i++) {
		int a;
		cin >> a;
		cout << binary_search(V1.begin(), V1.end(), a) << '\n';
	}
	return 0;
}