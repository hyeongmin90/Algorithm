#include <bits/stdc++.h>
#define ll long long

using namespace std;

bool arr[1000001];

int main(){
    ll min_, max_;
    cin >> min_ >> max_;

    ll ans = max_ - min_ + 1;

    for (ll i = 2; i * i <= max_; i++){
        ll a = min_ / (i * i);
        if (a * (i * i) < min_) a++;

        while(a * (i * i) <= max_){
            if(!arr[a * (i * i) - min_]){
                arr[a * (i * i) - min_] = true;
                ans--;
            }
            a++;
        }
    }
    cout << ans << '\n';
}