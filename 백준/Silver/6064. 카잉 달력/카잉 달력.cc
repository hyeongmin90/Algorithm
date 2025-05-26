#include <bits/stdc++.h>

using namespace std;

void func(){
    int m, n, x, y;
    cin >> m >> n >> x >> y;
    int nx, ny;
    nx = x - min(x, y) + 1;
    ny = y - min(x, y) + 1;
    int cnt = 1;
    int mx = 1, my = 1;
    bool flag = false;
    while(1){
        if (nx == mx && ny == my){
            cnt += x - nx;
            flag = true;
            break;
        }
        if (mx == m - min(m, n) + 1 && my == n - min(m, n) + 1) break;
        if(m - mx > n - my){
            cnt += n - my + 1;
            mx += n - my + 1;
            my = 1;
        }
        else{
            cnt += m - mx + 1;
            my += m - mx + 1;
            mx = 1;
        }
    }
    if(flag) cout << cnt << '\n';
    else cout << -1 << '\n';
}

int main(){
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t; cin >> t;
    while(t--){
        func();
    }
}