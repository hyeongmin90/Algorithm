#include <iostream>
#include <cmath>
using namespace std;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    int x1, y1, r1, x2, y2, r2, t;
    cin >> t;
    for (int i = 0; i < t; i++) {
        cin >> x1 >> y1 >> r1 >> x2 >> y2 >> r2;
        double d = sqrt(pow((x1 - x2), 2) + pow((y1 - y2), 2));
        if (d == 0 && r1 == r2) cout << "-1\n";
        else if (r1 + r2 == d || d + min(r1, r2) == max(r1, r2)) cout << "1\n";
        else if (d + min(r1, r2) < max(r1, r2) || r1 + r2 < d) cout << "0\n";
        else cout << "2\n";
    }

    return 0;
}