#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
int main() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    vector<int>V;
    int T, n;
    cin >> T;
    for (int i = 0; i < T; i++) {
        cin >> n; 
        V.push_back(n);     
    }
    sort(V.begin(),V.end());
    for (int i = 0; i < T; i++) {
        cout << V[i] << '\n';
    }
    return 0;
}