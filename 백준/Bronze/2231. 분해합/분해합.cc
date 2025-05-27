#include <iostream>

using namespace std;
int math(int i) {
    int a = i;
    while (i != 0) {
        a += (i % 10);
        i /= 10;
    }
    return a;
}
int main() {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        if (math(i) == n) {
            cout << i;
            break;
        }
        else if (i == n - 1) cout << "0";
    }
    return 0;
}