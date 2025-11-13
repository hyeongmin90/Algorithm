#include <bits/stdc++.h>
#define ll long long

using namespace std;

int main(){
    ll n, k;
    cin >> n >> k;
    
    ll len = 0;
    ll a = 9, b = 9, c = 1;
    
    while(n > a){
        len += b * c++;
        a = a * 10 + 9;
        b *= 10;
    }
    len += (n - a / 10) * c;


    if(len < k) {
        cout << -1 << '\n';
        return 0;
    }

    ll tmp = k;
    ll na = 9, nc = 1;
    while(tmp > na * nc){
        tmp -= na * nc++;
        na *= 10;
    }

    ll d = tmp / nc;
    ll nd = tmp % nc;
    ll m = pow(10, nc - 1) - 1;
    ll ans = m + d;
    if(nd == 0){
        cout << ans % 10 << '\n';
    }
    else{
        string str = to_string(ans + 1);
        cout << str[nd - 1] << '\n';
    }
    
}