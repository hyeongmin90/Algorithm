#include <bits/stdc++.h>

using namespace std;

bool arr[101];

int main(){
    int n;
    cin >> n;
    for(int i = 1; i <= n; i++)
        cin >> arr[i];
    
    int m; cin >> m;
    for(int i = 0; i < m; i++){
        int a, b;
        cin >> a >> b;
        if(a == 1){
            for(int i = b; i <= n; i += b)
                arr[i] = (arr[i] == 1 ? 0 : 1);
        }
        else{
            int x = b, y = b;
            while(1){
                if(x < 1 || y > n)break;
                if(arr[x] != arr[y])break;
                int c = (arr[x] == 1 ? 0 : 1);
                arr[x--] = c;
                arr[y++] = c;
            }
        }
    }
    int cnt = 1;
    while(cnt < n){
        for(int j = 0; cnt <= n && j < 20; j++){
            cout << arr[cnt++] << ' ';
        }
        cout << '\n';
    }
}