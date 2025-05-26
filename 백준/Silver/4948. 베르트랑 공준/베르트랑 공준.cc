#include <iostream>
#include <cmath>

#define max 250000
int num[250001];
using namespace std;
int main() {
	ios::sync_with_stdio(false); 
	cin.tie(NULL); cout.tie(NULL);
	int n, cnt;
	
	for (int i = 2; i <= max; i++) {
		num[i] = i;
	}
	for (int i = 2; i <= sqrt(max); i++) {
		if (num[i] == 0)continue;
		for (int j = i * i; j <= max; j += i) {
			num[j] = 0;
		}
	}
	while (1) {
		cin >> n;
		if (n == 0) break;
		cnt = 0;
		for (int i = n+1; i <= 2 * n; i++) {
			if (num[i] != 0) cnt++;
		}
		cout << cnt << '\n';
	}
    return 0;
}