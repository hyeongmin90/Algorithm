#include <iostream>
#include <cmath>

using namespace std;
int main() {
    int a[100][100] = {};
    int T;
    int cnt = 0;
    cin >> T;
    for (int k = 0; k < T; k++) {
        int x, y;
        cin >> x >> y;
        for (int i = y; i < y + 10; i++) {
            for (int j = x; j < x + 10; j++) {
                a[i][j] = 1;
            }
        }
    }
    for (int i = 0; i < 100; i++) {
        for (int j = 0; j < 100; j++) {
            if (a[i][j] == 1) cnt++;
        }
    }
    cout << cnt;
    
    return 0;
}