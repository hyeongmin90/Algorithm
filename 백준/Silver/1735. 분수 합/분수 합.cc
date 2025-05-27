#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;
int GCD(int a, int b) {
	if (b == 0)return a;
	else return GCD(b, a % b);
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	int A, B, C, D;
	cin >> A >> B >> C >> D;
	int num = (D * B) / GCD(D, B);
	int num2 = A * (num / B) + C * (num / D);
	int num3 = GCD(num, num2);
	cout << num2 / num3 << " "<<num / num3;
	return 0;
}