#include <bits/stdc++.h>

using namespace std;

int dp[1001];
int dp2[1001];
unordered_map<int, int> M;
long long ans;

int main(){
    ios::sync_with_stdio(0), cout.tie(0), cin.tie(0);
    int t, n, m;
    cin >> t >> n;
    for(int i = 1; i <= n; i++){
        int a; cin >> a;
        dp[i] = dp[i - 1] + a;
    }
        

    cin >> m;
    for(int i = 1; i <= m; i++){
        int a; cin >> a;
        dp2[i] = dp2[i - 1] + a;
    }

    for(int i = 1; i <= m; i++){
        for(int j = 0; j < i; j++){
            M[dp2[i] - dp2[j]]++;
        }
    }

    for(int i = 1; i <= n; i++){
        for(int j = 0; j < i; j++){
            int num = dp[i] - dp[j];
            ans += M[t - num];
            
        }
    }
    cout << ans << '\n';
}