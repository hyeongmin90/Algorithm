#include <iostream>

using namespace std;
int main() {
    int n, i;
    int A=1;
    cin >> n;
    for (i = 1; n > A; i++) {
        A = A + i * 6;
    }
    cout << i;
   
    return 0;
 }