#include <bits/stdc++.h>

using namespace std;

int d, n;
vector<int> oven;

int main(){
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> d >> n;
    int min_wide = INT_MAX;
    for(int i = 0; i < d; i++){
        int wide;
        cin >> wide;
        min_wide = min(wide, min_wide);
        oven.push_back(min_wide);
    }
    auto e = oven.end();
    int ans = 0;
    for(int i = 0; i < n; i++){
        int a;
        cin >> a;
        auto it = upper_bound(oven.begin(), e, a, greater<int>());

        if (it == oven.begin()) {
            cout << 0 << '\n';
            return 0;
        }
        it--;
        int idx = it - oven.begin();
        ans = idx + 1;
        e = it;
    }
    cout << ans << '\n';
}