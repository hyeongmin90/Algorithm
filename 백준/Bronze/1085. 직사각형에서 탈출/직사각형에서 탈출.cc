#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    int x, y, w, h;
    cin >> x >> y >> w >> h;
    cout << min(min((w - x),(x)), min((h - y),(y)));
    return 0;
}