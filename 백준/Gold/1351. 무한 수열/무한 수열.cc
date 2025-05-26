#include <bits/stdc++.h>
#define ll long long

using namespace std;

unordered_map<ll, ll> m;
ll n, p, q;

ll func(ll n){
    if(m.find(n) != m.end()){
        return m[n];
    }
    
    ll nn = func(n/p) + func(n/q);
    m[n] = nn;
    return nn;
}

int main(){
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> n >> p >> q;
    m[0] = 1;
    if(!n) {
        cout << 1 << '\n';
        return 0;
    }

    cout << func(n/p) + func(n/q) << '\n';
}