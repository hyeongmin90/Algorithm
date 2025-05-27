#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

long long arr[101];
int main()
{
	int maxnum = -1000;
	int t , M = -1000;
	cin >> t;
	vector<int>V(t);
	for (int i = 0; i < t; i++) {
		int a;
		cin >> a;
		V[i] = a;
		M = max(M, a);
	}
	int num = 0;
	for (int i = 0; i < t; i++) {
		if (V[i] < 0 && num < abs(V[i])) {
			num = 0;
			continue;
		}
		num += V[i];
		maxnum = max(maxnum, num);
	}
	cout << max(M,maxnum);
	return 0;
}