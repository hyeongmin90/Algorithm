#include <iostream>
#include <cmath>

using namespace std;
int main() {
    int a[2001] = {};
    int T;
    cin >> T;
    for (int k = 0; k < T; k++) {
        int n;
        cin >> n;
        if (n == 0) a[1000] = 1001;
        else a[n + 1000] = n;
    }
    for (int i = 0; i <= 2000; i++) {
        if (a[i] == 1001) cout << 0 << '\n';
        else if (a[i] != 0)cout << a[i] << '\n';
    }
    return 0;
}