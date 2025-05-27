#include <bits/stdc++.h>

using namespace std;

int rope[100001];

int main(){
    int n;
    cin >> n;
    for(int i = 0; i < n; i++)
        cin >> rope[i];
    
    sort(rope, rope + n);
    int ans = 0;
    for(int i = 1; n - i >= 0; i++){
        ans = max(ans, rope[n - i] * i);
    }
    cout << ans << '\n';
}