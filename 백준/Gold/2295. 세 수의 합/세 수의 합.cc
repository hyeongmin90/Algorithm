#include <bits/stdc++.h>

using namespace std;

int arr[1001];
unordered_set<int> s;

int main(){
    int n; cin >> n;
    for(int i = 0; i < n; i++)
        cin >> arr[i];

    sort(arr, arr + n);

    for(int i = 0; i < n; i++){
        for(int j = i; j < n; j++){
            s.insert(arr[i] + arr[j]);
        }
    }

    for(int i = n - 1; i >= 0; i--){
        for(int j = i; j >= 0; j--){
            if(s.find(arr[i] - arr[j]) != s.end()){
                cout << arr[i] << '\n';
                return 0;
            }
        }
    }
    
}