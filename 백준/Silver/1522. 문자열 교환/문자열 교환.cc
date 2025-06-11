#include <bits/stdc++.h>

using namespace std;

int main(){
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    string str;
    cin >> str;
    int cnt = 0, ans = 10000;
    int n = str.size();
    for(int i = 0; i < n; i++){
        if(str[i] == 'a') cnt++;
    }
    
    for(int i = 0; i < n; i++){
        int cnt2 = 0;
        for(int j = i; j < i + cnt; j++){
            if(str[(j % n)] == 'b') cnt2++;
        }
        ans = min(ans, cnt2);
    }
    cout << ans << '\n';
}