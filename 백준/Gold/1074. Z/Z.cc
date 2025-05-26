#include <iostream>
#include <algorithm>
#include <queue>
#include <cmath>
using namespace std;
int func(int n, int r, int c) {
	if (n == 0)return 0;
	int half = pow(2, n - 1);
	if (r < half && c < half) return func(n - 1, r, c);
	if (r < half && c >= half) return half * half + func(n - 1, r, c - half);
	if (r >= half && c < half) return 2 * half * half + func(n - 1, r - half, c);
	return 3 * half * half + func(n - 1, r - half, c - half);
}


int main()
{
	int N, r, c;
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	cin >> N >> r >> c;
	cout << func(N, r, c);
	
	return 0;
}