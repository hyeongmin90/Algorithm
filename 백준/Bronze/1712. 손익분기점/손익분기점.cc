#include <iostream>

using namespace std;
int main() {
   
    long long A, B, C, i;
    cin >> A >> B >> C;
    if (B >= C) {
        cout << -1;
        return 0;
    }
    if (A + B < C) cout << 1;
    else {
        i = A / (C - B);
        
        cout << i+1;
    }
    return 0;
 }