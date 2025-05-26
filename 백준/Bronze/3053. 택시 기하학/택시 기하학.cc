#include <iostream>

using namespace std;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    double n, pi = 3.14159265358979;
    cin >> n;
    cout << fixed;
    cout.precision(6);
    cout << n * n * pi << '\n';
    cout << 2 * n * n;
    return 0;
}