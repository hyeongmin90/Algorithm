#include <bits/stdc++.h>

using namespace std;

int func(int x, int y){
    int n = y - x;
    if (n <= 1) return n;
    int i = 0, ans = 0;
    long long dist = 0;
    while(1){
        i++;
        dist += i * 2;
        ans += 2;
        if (dist == n) return ans;

        if(dist > n){
            int a = dist - n;
            if (a < i) return ans;
            if (a >= i) return ans - 1;
        }
    }
}

int main(){
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t;
    cin >> t;
    while(t--){
        int x, y;
        cin >> x >> y;
        cout << func(x, y) << '\n';
    }
}