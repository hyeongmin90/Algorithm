#include <iostream>
#include <algorithm>

using namespace std;
int arr[1000][3] = {};
int main()
{
	int cost[3];
	int t;
	cin >> t;
	for (int i = 1; i <= t; i++) {
		cin >> cost[0] >> cost[1] >> cost[2];
		arr[i][0] = min(arr[i - 1][1], arr[i - 1][2]) + cost[0];
		arr[i][1] = min(arr[i - 1][0], arr[i - 1][2]) + cost[1];
		arr[i][2] = min(arr[i - 1][0], arr[i - 1][1]) + cost[2];
	}
	cout << min(arr[t][0], min(arr[t][1], arr[t][2]));
	return 0;
}