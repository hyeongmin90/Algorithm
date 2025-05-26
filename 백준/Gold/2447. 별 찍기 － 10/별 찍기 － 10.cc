#include <iostream>
using namespace std;

void star(int i, int j,int T) {
    if ((i / T) % 3 == 1 && (j / T) % 3 == 1) {
        cout << ' ';
    }
    else {
        if (T / 3 == 0) cout << '*';
        else star(i, j, T / 3);
    }
}
int main() {
    int T;
    cin >> T;
    for (int i = 0; i < T; i++) {
        for (int j = 0; j < T; j++) {
            star(i, j, T);
        }
        cout << '\n';
    }
    return 0;
}