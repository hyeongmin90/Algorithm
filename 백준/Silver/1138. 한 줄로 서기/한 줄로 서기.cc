#include <bits/stdc++.h>

using namespace std;

int arr[11];
list<int> ans;

int main(){
    int n; cin >> n;
    for(int i = 1; i <= n; i++){
        cin >> arr[i];
    }
    for(int i = n; i > 0; i--){
        list<int>::iterator it = ans.begin();
        advance(it, arr[i]);
        ans.insert(it, i);
    }
    for(auto x : ans) cout << x << ' ';
}