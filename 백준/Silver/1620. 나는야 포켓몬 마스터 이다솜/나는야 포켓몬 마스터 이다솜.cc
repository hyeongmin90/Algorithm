#include <iostream>
#include <map>
#include <string>
#include <algorithm>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    int N, M;
    string A;
    map<string, string>M1;
    map<string, string>M2;
    cin >> N >> M;
    for (int i = 1; i <= N; i++) {
        cin >> A;
        M1[A] = to_string(i);
        M2[to_string(i)] = A;
    }
    for (int i = 0; i < M; i++) {
        cin >> A;
        if (isdigit(A[0]) == 0) cout << M1.find(A)->second << '\n';
        else cout << M2.find(A)->second << '\n';
    }
    return 0;
}