#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

using namespace std;

int main(){
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int n,a,b,c,d,sum=0;
    cin >> n;
    d = n;
    while(true) {
        a = d / 10; b = d % 10;
        c = (a + b) % 10;
        d = b * 10 + c;
        sum += 1;
        if (d == n) break;
    }
    cout << sum;
    return 0;
}