#include <bits/stdc++.h>

using namespace std;

int arr[2001];
int ans;


int main(){
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n; cin >> n;
    for(int i = 0; i < n; i++)
        cin >> arr[i];
    
    sort(arr, arr + n);
    for(int k = 0; k < n; k++){
        int i = 0, j = n - 1;
        while(i < j){
            if(i == k){
                i++;
                continue;
            }
            if(j == k){
                j--;
                continue;
            }
            if(arr[i] + arr[j] == arr[k]){
                ans++;
                break;
            }
            if(arr[i] + arr[j] < arr[k]) i++;
            else j--;
        }
    }
    cout << ans << '\n';   
}