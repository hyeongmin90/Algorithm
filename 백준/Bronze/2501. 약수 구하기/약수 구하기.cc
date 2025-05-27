#include <iostream>
#include <algorithm>
#include <vector>


using namespace std;
int main()
{
	vector<int>V;
	int n, k;
	cin >> n >> k;
	for (int i = 1; i*i <= n; i++) {
		if (i * i == n) V.push_back(i);
		else if (n % i == 0) {
			V.push_back(i);
			V.push_back(n / i);
		}
	}
	sort(V.begin(), V.end());
	if (V.size() < k)cout << 0;
	else cout << V[k - 1];

	return 0;
}