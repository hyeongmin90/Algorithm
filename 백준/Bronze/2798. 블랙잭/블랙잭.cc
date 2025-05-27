#include <iostream>

using namespace std;
int main() {
    int a[100];
    int N, M;
    int max = 0, b;
    cin >> N >> M;
    for (int i = 0; i < N; i++) {
        cin >> a[i];
    }
    for (int i = 0;i < N - 2; i++) {
        for (int j = i + 1;j < N - 1; j++) {
            for (int k = j + 1; k < N; k++) {
                b = a[i] + a[j] + a[k];
                if (b <= M && max < b) max = b;
            }
        }
    }
    cout << max;
    return 0;
}