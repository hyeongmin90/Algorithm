#include <bits/stdc++.h>

using namespace std;

int arr[101];

int main(){
    int n;
    cin >> n;
    for(int i = 0; i < n; i++)
        arr[i] = i + 1;

    for(int i = 0; i < n; i++){
        int m; cin >> m;
        int a = i;
        while(m--){
            swap(arr[a], arr[a - 1]);
            a--;
        }
    }

    for(int i = 0; i < n; i++)
        cout << arr[i] << ' ';

}