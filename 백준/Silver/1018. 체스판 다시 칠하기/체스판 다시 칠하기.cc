#include <iostream>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    char board[51][51];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> board[i][j];
        }
    }
    int h = (n - 7) * (m - 7);
    int cnt = 0, cnt2 = 0;
    int min = 65;
    int c;
    int a = 0, b = 0;
    while (h-- != 0) {
        for (int i = a; i < a + 8; i++) {
            for (int j = b; j < b + 8; j++) {
                if (i % 2 == 0 && j % 2 == 0 || i % 2 == 1 && j % 2 == 1) {
                    if (board[i][j] == 'B')cnt++;
                }
                else {
                    if (board[i][j] == 'B')cnt2++;
                }
            }
        }
        if (cnt > cnt2) c = cnt2 + (32 - cnt);
        else c = cnt + (32 - cnt2);
        if (c < min)min = c;
        cnt = 0;
        cnt2 = 0;
        b++;
        if (b > m - 8) {
            b = 0;
            a++;
        }    
    }
    cout << min;
    return 0;
}