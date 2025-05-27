#include <iostream>
#include <algorithm>
using namespace std;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    int k, cnt[5] = {};
    int a = 1, b = 1;;
    int arr[6][2];
    cin >> k;
    for (int i = 0; i < 6; i++) {
        cin >> arr[i][0] >> arr[i][1];
        cnt[arr[i][0]]++;
    }
    for (int i = 0; i < 6; i++) {
        if (cnt[arr[i][0]] == 1) {
            a *= arr[i][1];
            continue;
        }
        if (arr[i][0] == arr[(i + 2) % 6][0]) b *= arr[(i + 1) % 6][1];
    }
    cout << (a - b) * k;
    return 0;
}