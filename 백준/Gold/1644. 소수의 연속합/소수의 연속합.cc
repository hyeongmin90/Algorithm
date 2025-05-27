#include <bits/stdc++.h>

using namespace std;

int n;
bool notprime[4000001];
vector<int> v;

int main(){
    cin >> n;
    /* 소수 판별 */
    for (int i = 2; i * i <= n; i++){
        if(notprime[i])continue;
        for (int j = i * i; j <= n; j += i){
            notprime[j] = 1;
        }
    }
    for (int i = 2; i <= n; i++)
        if(!notprime[i])
            v.push_back(i);

    int sz = v.size(), j = 0, sum = 0, ans = 0;

    for (int i = 0; i < sz; i++){
        while(j < sz && sum < n){
            sum += v[j++];
        }
        if(sum == n)
            ans++;
        sum -= v[i];
    }
    cout << ans << '\n';
}