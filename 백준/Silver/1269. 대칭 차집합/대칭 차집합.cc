#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    int n, m, a;
    int cnt = 0;
    cin >> n >> m;
    vector<int>V(n);
    for (int i = 0; i < n; i++) {
        cin >> a;
        V[i] = a;
    }
    sort(V.begin(), V.end());
    for (int i = 0; i < m; i++) {
        cin >> a;
        if (binary_search(V.begin(),V.end(),a)) cnt++;
    }
    cout << m + n - 2 * cnt;
    return 0;
}