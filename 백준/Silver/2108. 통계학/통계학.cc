#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

int main() {
    ios::sync_with_stdio(false); 
    cin.tie(NULL); cout.tie(NULL);
    int A[8001] = {};
    double T;
    double sum = 0;
    int max = -4000, min = 4000;
    int n, num = 0, number = 0;
    int p = 1;
    vector<int>V;
    cin >> T;
    for (int i = 0; i < T; i++) {
        cin >> n;
        V.push_back(n);
        sum += n;
        if (max < n)max = n;
        if (min > n)min = n;
        A[n + 4000] += 1;
    }
    sort(V.begin(), V.end());
    for (int i = min + 4000; i <= max + 4000 ; i++) {
        if (A[i] > 0) {
            if (A[i] > num) { num = A[i]; number = i - 4000; p = 1; }
            else if (p == 1 && A[i] == num) { 
                number = i - 4000;
                p = 0;
            }
        }
    }
    cout << floor((sum / T) + 0.5) << '\n';
    cout << V[T / 2] << '\n';
    cout << number << '\n';
    cout << max - min;
    return 0;
}