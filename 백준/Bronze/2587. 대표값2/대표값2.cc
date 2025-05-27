#include <iostream>
#include <cmath>

using namespace std;
int main() {
    int a[100] = {};
    int b[5] = {};
    int sum = 0, l = 0, j = 1;
    for (int k = 0; k < 5; k++) {
        int n;
        cin >> n;
        sum += n;
        if (a[n] == n) { a[n + j] = n; j++; }
        a[n] = n;
    }
    for (int i = 0; i < 100; i++) {
        if (a[i] != 0) { b[l] = a[i]; l++; }
    }
    cout << sum / 5 <<'\n'<< b[2];
    return 0;
}