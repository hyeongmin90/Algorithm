#include <bits/stdc++.h>

#define ll long long

using namespace std;

int main(){
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        map<ll, ll> army;
        for(int i = 0; i < n; i++){
            ll a;
            cin >> a;
            army[a]++;
        }
        bool flag = false;
        for(auto pair : army){
            if((n % 2 == 0 && pair.second > n / 2) || (n % 2 != 0 && pair.second >= (n + 1) / 2)){
                cout << pair.first << '\n';
                flag = true;
            }
        }
         if(!flag) cout << "SYJKGW" << '\n';
    }
}