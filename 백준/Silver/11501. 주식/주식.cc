#include <bits/stdc++.h>

using namespace std;

int main(){
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t; cin >> t;
    while(t--){
        vector<int> v;
        int n; cin >> n;
        for(int i = 0; i < n; i++){
            int a; cin >> a;
            v.push_back(a);
        }
        long long ans = 0;
        int MAX = 0;
        for(int i = n - 1; i >= 0; i--){
            if(v[i] > MAX){
                MAX = v[i];
                continue;
            }
            ans += MAX - v[i];
        }
        cout << ans << '\n';
    }
}