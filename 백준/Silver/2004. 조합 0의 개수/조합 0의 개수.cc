#include <iostream>
#include <map>
#include <algorithm>

using namespace std;
long long count(long long a, int b) {
	long long ans = 0;
	for (long long i = b; i <= a; i *= b) {
		ans += a / i;
	}
	return ans;
}
int main()
{
	long long n , m;
	cin >> n >> m;
	long long d1 = count(n, 2) - count(m, 2) - count(n - m, 2);
	long long d2 = count(n, 5) - count(m, 5) - count(n - m, 5);
	cout << min(d1, d2);

	return 0;
}