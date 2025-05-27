#include <iostream>

using namespace std;
int main() {
    int a, n, cnt, b = 0;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a;
        cnt = 0;
        for (int j = 2; j < a; j++) {
            if (a % j == 0) cnt++;
        }
        if (a != 1 && cnt == 0)b++;
    }
    cout << b << endl;
    return 0;
 }