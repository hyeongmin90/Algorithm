#include <bits/stdc++.h>

using namespace std;

int d, n;
vector<int> oven;

int main(){
    cin >> d >> n;
    int min_wide = INT_MAX;
    for(int i = 0; i < d; i++){
        int wide;
        cin >> wide;
        min_wide = min(wide, min_wide);
        oven.push_back(min_wide);
    }
    auto e = oven.end();
    for(int i = 0; i < n; i++){
        int a;
        cin >> a;
        auto it = upper_bound(oven.begin(), e, a, greater<int>()) - 1;
        int idx = it - oven.begin();
        
        if(i == n - 1){
            cout << idx + 1<< '\n';
        }
        e = it;
    }
}