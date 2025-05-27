#include <bits/stdc++.h>

using namespace std;

long long arr[5001];
int ans[3];
long long cnt = 0x7fffffffffffffff;

int main(){
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n; cin >> n;
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }

    sort(arr, arr + n);

    for(int i = 0; i < n - 2; i++){
        int lo = i + 1;
        int hi = n - 1;
        while(lo < hi){
            long long sum = abs(arr[i] + arr[lo] + arr[hi]);
            if(cnt > sum){
                cnt = sum;
                ans[0] = arr[i];
                ans[1] = arr[lo];
                ans[2] = arr[hi];
            }
            if(abs(arr[i] + arr[lo + 1] + arr[hi]) < abs(arr[i] + arr[lo] + arr[hi - 1]))
                lo++;

            else hi--;
        }
    }
    for(auto x : ans) cout << x << ' ';

}