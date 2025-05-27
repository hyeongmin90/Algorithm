#include <bits/stdc++.h>

using namespace std;

int arr[51];

int main(){
    int n, s, p;
    cin >> n >> s >> p;
    int rank = 100, cnt = 0;
    fill(arr + 1, arr + p + 1, -1);
    for(int i = 1; i <= n; i++)
        cin >> arr[i];

    sort(arr + 1, arr + n + 1, greater<>());
    for(int i = 1; i <= p; i++){
        if(arr[i] > s) continue;
        if(rank == 100) rank = i;
        if(arr[i] == s) cnt++;
    }
        
    cout << (rank + cnt > p ? -1 : rank) << '\n';
}