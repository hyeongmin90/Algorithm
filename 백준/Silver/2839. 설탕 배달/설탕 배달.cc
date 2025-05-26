#include <iostream>

using namespace std;
int main() {
    int n,a;
    int cnt = 0;
    cin >> n;
    while (n > 0) {
        if (n < 15 && n % 3 == 0){n -= 3;}
        else n -= 5;
        cnt++;
    }
    if (n < 0)cout << -1;
    else cout << cnt << endl;
    
    return 0;
 }