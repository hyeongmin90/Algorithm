#include <bits/stdc++.h>
#define ll long long

using namespace std;

int main(){
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t; cin >> t;
    while(t--){
        ll ans = 0;
        priority_queue<ll, vector<ll>, greater<ll>> pq;
        int n; cin >> n;
        while(n--){
            int num;
            cin >> num;
            pq.push(num);
        }
        while(pq.size() > 1){
            ll s1 = pq.top();
            pq.pop();
            ll s2 = pq.top();
            pq.pop();
            ll tmp = s1 + s2;
            ans += tmp;
            pq.push(tmp);
        }
        cout << ans << '\n';
    }
}