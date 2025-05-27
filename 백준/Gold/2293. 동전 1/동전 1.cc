#include <bits/stdc++.h>

using namespace std;

vector<int> v;
int dp[10002];
int n, k;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    cin >> n >> k;
    for (int i = 0; i < n; i++){
        int num;
        cin >> num;
        if(num <= k)
            v.push_back(num);
    }
    sort(v.begin(),v.end());
    dp[0] = 1;
    for (int i = 0; i < v.size(); i++){
        for (int j = 1; j <= k; j++){
            if(j >= v[i])
                dp[j] = dp[j] + dp[j - v[i]];
        }
    }
    cout << dp[k];
    return 0;
}