#include <bits/stdc++.h>

using namespace std;

int arr[30001];
int check[3001];

int main(){
    int n, d, k, c;
    cin >> n >> d >> k >> c;
    for(int i = 0; i < n; i++)
        cin >> arr[i];
    
    int j = 0, ans = 0, dupl = 0, coup = 0;
    for(int i = 0; i < n; i++){
        while(j - i < k){
            check[arr[j % n]]++;
            if(check[arr[j % n]] >= 2) dupl++;
            if(arr[j % n] == c) coup++;
            j++;
        }
        ans = max(ans, k - dupl + !coup);
        check[arr[i]]--;
        if(arr[i] == c) coup--;
        if(check[arr[i]] >= 1) dupl--;
    }
    cout << ans << '\n';
}