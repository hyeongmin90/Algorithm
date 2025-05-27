#include <iostream>

using namespace std;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    int n, m;
    int max = 0;
    int t;
    cin >> t;
    while (t--) {
        cin >> n >> m;
        for (int i = 1;; i++) {
            if ((n * i) % m == 0) {
                max = n * i;
                break;
            }
        }
        cout << max <<'\n';
    }
    return 0;
}