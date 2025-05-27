#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

int main() {
    int n, i, a[10];
    cin >> n;
    for (i = 0; n != 0; i++) {
        a[i] = n % 10;
        n /= 10;
    }
    sort(a,a + i,greater<>());
    for (int j = 0; j < i; j++) {
        cout << a[j];
    }
    return 0;
}