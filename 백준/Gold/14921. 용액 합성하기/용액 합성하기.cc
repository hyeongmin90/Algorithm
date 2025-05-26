#include <bits/stdc++.h>

using namespace std;

int arr[100001];
int ans;
int num = 0x7fffffff;

int main(){
    int n; cin >> n;
    for(int i = 0; i < n; i++)
        cin >> arr[i];
    
    int i = 0, j = n - 1;
    while(i < j){
        int sum = abs(arr[i] + arr[j]);
        if(num > sum){
            num = sum;
            ans = arr[i] + arr[j];
        }
        if(abs(arr[i + 1] + arr[j]) < abs(arr[i] + arr[j - 1])) i++;
        else j--;
    }
    cout << ans << '\n';
}