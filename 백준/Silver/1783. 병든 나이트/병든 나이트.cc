#include <bits/stdc++.h>

using namespace std;

int func(int n, int m){
    if(n == 1) return 1;
    if(n < 3) return (m >= 7 ? 4 : m / 2 + m % 2);
    if(m < 7) return (m <= 4 ? m : 4);
    return m - 2;
}

int main(){
    int n, m;
    cin >> n >> m;
    cout << func(n, m) << '\n';
}