#include <bits/stdc++.h>

using namespace std;

int n, m;
int arr[10001];

int main(){
    cin >> n >> m;
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    int j = 0, sum = 0, ans = 0;
    for (int i = 0; i < n; i++){
        while(j < n && sum < m){
            sum += arr[j++];
        }
        if(sum == m)
            ans++;
        sum -= arr[i];
    }
    cout << ans << '\n';
}