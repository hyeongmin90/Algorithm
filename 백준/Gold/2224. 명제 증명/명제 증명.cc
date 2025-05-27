#include <bits/stdc++.h>

using namespace std;

int arr[53][53];
int M = 0x3f3f3f3f;
int cnt;

int toNum(char a){
    if(a >= 'a') return (a - 'a' + 26);
    return a - 'A';
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    for(int i = 0; i < 53; i++)
        fill(arr[i], arr[i] + 53, M);

    for(int i = 0; i < 53; i++)
        arr[i][i] = 0;

    int n; cin >> n;
    for(int i = 0; i < n; i++){
        char a, b;
        string _;
        cin >> a >> _ >> b;
        arr[toNum(a)][toNum(b)] = 1;
    }
    
    for(int k = 0; k < 53; k++){
        for(int i = 0; i < 53; i++){
            for(int j = 0; j < 53; j++){
                if(arr[i][j] > arr[i][k] + arr[k][j]){
                    arr[i][j] = 1;
                }
            }
        }
    }
    for(int i = 0; i < 53; i++){
        for(int j = 0; j < 53; j++){
            if(arr[i][j] != M && i != j){
                cnt++;
            }
        }
    }
    cout << cnt << '\n';
    for(int i = 0; i < 53; i++){
        for(int j = 0; j < 53; j++){
            if(arr[i][j] != M && i != j){
                if(i < 26) cout << char(i + 'A') << " => ";
                else cout << char(i - 26 + 'a') << " => ";
                if(j < 26) cout << char(j + 'A');
                else cout << char(j - 26 + 'a');
                cout << '\n';
            }
        }
    }
}