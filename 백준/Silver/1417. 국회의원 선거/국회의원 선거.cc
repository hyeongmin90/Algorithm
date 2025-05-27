#include <bits/stdc++.h>

using namespace std;

int arr[51];

int main(){
    int n; cin >> n;
    for(int i = 0; i < n; i++)
        cin >> arr[i];
    int ans = 0;
    while(1){
        int Max = arr[0];
        int idx = 0;
        int Mx = *max_element(arr + 1, arr + n);
        if(Max > Mx)break;
        for(int i = 1; i < n; i++){
            if(arr[i] >= Max){
                Max = arr[i];
                idx = i;
            }
        }
        arr[idx]--;
        arr[0]++;
        ans++;
    }
    cout << ans << '\n';

}
