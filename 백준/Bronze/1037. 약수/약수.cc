#include <iostream>
#include <cmath>
using namespace std;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    int n;
    int max = 0;
    int min = 1000001;
    cin >> n;
    while (n--) {
        int a;
        cin >> a;
        if (max < a) max = a;
        if (min > a) min = a;
    }
    cout << max * min;
    return 0;
}