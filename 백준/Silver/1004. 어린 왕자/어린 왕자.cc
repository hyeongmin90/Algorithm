#include <iostream>
#include <cmath>
using namespace std;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    int t;
    cin >> t;
    for (int i = 0; i < t; i++) {
        int cnt = 0;
        int x1, y1, x2, y2, k;
        cin >> x1 >> y1 >> x2 >> y2 >>k;
        for (int j = 0; j < k; j++) {
            int x, y, r;
            cin >> x >> y >> r;
            double d1 = hypot(x1 - x, y1 - y);
            double d2 = hypot(x2 - x, y2 - y);
            if ((d1 < r && d2 > r)||(d1 > r && d2 < r)) cnt++;
        }
        cout << cnt << '\n';
    }
    return 0;
}