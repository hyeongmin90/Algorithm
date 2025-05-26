#include <bits/stdc++.h>

using namespace std;

int func(int x, int y){
    int m = max(abs(x), abs(y));
    int n = 2 * m + 1;
    n *= n;
    if(m == x) return n - m + y;
    n -= 2 * m;
    if(m == -y) return n - m + x;
    n -= 2 * m;
    if(m == -x) return n - m - y;
    n -= 2 * m;
    return n - m - x; //if(m == y)
}

int main(){
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int r1, c1, r2, c2;
    cin >> r1 >> c1 >> r2 >> c2;

    int maxVal = 0;
    for(int i = r1; i <= r2; i++){
        for(int j = c1; j <= c2; j++){
            maxVal = max(maxVal, func(i, j));
        }
    }
    int format = log10(maxVal) + 1;
    for(int i = r1; i <= r2; i++){
        for(int j = c1; j <= c2; j++){
            int a = func(i, j);
            cout << setw(format) << a << ' ';
        }
        cout << '\n';
    }
}