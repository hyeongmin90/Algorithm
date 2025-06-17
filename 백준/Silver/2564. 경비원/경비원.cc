#include <bits/stdc++.h>

using namespace std;

int store[101];
int w, h, n, ans;

int calculate(int dir, int dist){
    if(dir == 1) return dist;
    if(dir == 4) return w + dist;
    if(dir == 2) return w + h + (w - dist);
    return w + h + w + (h - dist);
}

int main(){
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> w >> h >> n;
    for(int i = 0; i < n; i++){
        int dir, dist;
        cin >> dir >> dist;
        store[i] = calculate(dir, dist);
    }
    int a, b;
    cin >> a >> b;
    int cur = calculate(a, b);
    for(int i = 0; i < n; i++){
        int d = abs(store[i] - cur);
        ans += min(d, 2 * (w + h) - d);
    }
    cout << ans << '\n';
}
