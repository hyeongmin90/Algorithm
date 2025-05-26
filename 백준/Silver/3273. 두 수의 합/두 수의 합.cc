#include <bits/stdc++.h>

using namespace std;

int arr[100001];

int main(){
    int n, x;
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }
    cin >> x;
    sort(arr, arr + n);
    int i = 0, j = n - 1;
    int ans = 0;
    while(i < j){
        int sum = arr[i] + arr[j];
        if(sum == x) ans++;
        if(sum >= x){
            j--;
        }
        else i++;
    }
    cout << ans << '\n';
}