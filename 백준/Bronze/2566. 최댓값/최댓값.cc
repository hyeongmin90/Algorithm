#include <iostream>
#include <cmath>

using namespace std;
int main() {
    int a[9][9] = {};
    int max = 0;
    int b, c;
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            cin >> a[i][j];
            if (a[i][j] >= max) {
                max = a[i][j];
                b = i; c = j;
            }
        }
    }
    cout << max << '\n' << b +1  << " " << c + 1;

    return 0;
}