#include <iostream>
#include <algorithm>
using namespace std;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    int n, m;
    int min = 0 , max = 0;
    cin >> n >> m;
    for (int i = 1; i < std::min(m,n) + 1; i++) {
        if (n % i == 0 && m % i == 0) {
            min = i;
        }
    }
    for (int i = 1;; i++) {
        if ((n * i) % m == 0) {
            max = n * i;
            break;
        }
    }
    cout << min<<" "<<max;
    return 0;
}