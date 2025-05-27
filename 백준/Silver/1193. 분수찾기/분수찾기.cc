#include <iostream>

using namespace std;
int main() {
    int n;
    int i,num=0;
    cin >> n;
    for (i = 1; num < n; i++){
        num += i;
    }
    int a = i - 1;
    int b = n - (num - a);
   
    if (a % 2 == 0) cout << b << "/" << a - b + 1;
    if (a % 2 != 0) cout << a - b + 1 << "/" << b;

    return 0;
 }