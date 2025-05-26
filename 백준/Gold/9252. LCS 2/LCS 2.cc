#include <bits/stdc++.h>

using namespace std;

int dp[1001][1001];
string ans;

int main(){
    string a, b;
    cin >> a >> b;

    for(int i = 1; i <= a.length(); i++){
        for(int j = 1; j <= b.length(); j++){
            if(a[i - 1] == b[j - 1]){
                dp[i][j] = dp[i - 1][j - 1] + 1;
            }
            else{
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }
    int i = a.length();
    int j = b.length();
    cout << dp[i][j] << '\n';

    while(i > 0 && j > 0){
        if(a[i - 1] == b[j - 1]){
            ans += a[i - 1];
            i--;
            j--;
        }
        else{
            if(dp[i][j] == dp[i - 1][j])
                i--;
            else j--;
        }
    }
    reverse(ans.begin(), ans.end());
    cout << ans << '\n';
}