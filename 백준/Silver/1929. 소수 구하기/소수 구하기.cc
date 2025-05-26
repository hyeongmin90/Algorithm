#include <iostream>
#include <cmath>

#define max 1000000
int num[1000001];
using namespace std;
int main() {
	ios::sync_with_stdio(false); 
	cin.tie(NULL); cout.tie(NULL);
	int n,m;
	
	cin >> m >> n;
	
	for (int i = 2; i <= max; i++) {
		num[i] = i;
	}
	for (int i = 2; i <= sqrt(max); i++) {
		if (num[i] == 0)continue;
		for (int j = i * i; j <= max; j += i) {
			num[j] = 0;
		}
	}
	for (int i = m; i <= n; i++) {
		if (num[i] != 0) cout << num[i] << '\n';
	}


    return 0;
}