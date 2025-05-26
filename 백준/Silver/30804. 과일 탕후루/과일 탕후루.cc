#include <bits/stdc++.h>

using namespace std;

int arr[200001];
int fruit[11];

int func(int n){
    if(n <= 2) return n;
    int j = 0, cnt = 0, len = 0, ans = 0;

    for(int i = 0; i < n; i++){
        while(j < n && cnt <= 2){
            if(fruit[arr[j]] == 0)cnt++;
            fruit[arr[j++]]++;
        }
        len = j - i;
        if(cnt > 2) len--;
        ans = max(ans, len);
        fruit[arr[i]]--;
        if(fruit[arr[i]] == 0)cnt--;
    }
    return ans;
}

int main(){
    int n; cin >> n;
    for(int i = 0; i < n; i++)
        cin >> arr[i];
    
    cout << func(n) << '\n';

}