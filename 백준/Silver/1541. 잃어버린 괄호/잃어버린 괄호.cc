#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

int main()
{
	bool minus = false;
	int num = 0;
	int sum = 0;
	string A;
	cin >> A;
	for (int i = 0; i <= A.size(); i++) {
		if (A[i] > 47 && A[i] < 58) {
			num = num * 10 + (A[i] - '0');
		}
		else {
			if (minus) {
				sum -= num;
			}
			else {
				sum += num;
			}
			num = 0;
		}
		if (A[i] == '-') minus = true;
	}
	cout << sum;
	return 0;
}