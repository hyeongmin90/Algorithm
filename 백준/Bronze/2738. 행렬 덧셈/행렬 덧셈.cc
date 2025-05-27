#include <iostream>
#include <cmath>

using namespace std;
int main() {
    int a[100][100] = {};
    int n, m;
    int num;
    cin >> n >> m;
    for (int k = 0; k < 2; k++) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> num;
                a[i][j] += num;
            }
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cout << a[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}