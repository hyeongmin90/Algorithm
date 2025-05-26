#include <bits/stdc++.h>
#define MAXN 1000000
using namespace std;

bool Break[10];
int MIN = 0x7fffffff;
int num = 100, ans;

bool check(int n){
    if(n == 0 && Break[0]) return 0;
    while(n > 0){
        if(Break[n % 10]) return 0;
        n /= 10;
    }
    return 1;
}

int main(){
    int n, m;
    cin >> n >> m;
    for(int i = 0; i < m; i++){
        int a; cin >> a;
        Break[a] = 1;
    }
    if(m == 10){
        cout << abs(n - 100) << '\n';
        return 0;
    }
    for(int i = 0; i < MAXN; i++){
        if(!check(i)) continue;
        if(MIN > abs(i - n)){
            num = i;
            MIN = abs(i - n);
        }
    }

    ans = abs(n - num) + to_string(num).size();
    if(abs(100 - n) < ans) cout << abs(100 - n) << '\n';
    else cout << ans << '\n';
}