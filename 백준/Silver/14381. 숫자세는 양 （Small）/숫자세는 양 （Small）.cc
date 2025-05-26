#include <bits/stdc++.h>

using namespace std;

bool check[10];
int n;

void sol(){
    int cnt = 0;
    int tmp = n;
    int i = 1;
    int M = 10000;
    for(int i = 1; i < M; i++){
        tmp = n * i;
        while(tmp != 0){
            if(!check[tmp % 10]){
                check[tmp % 10] = 1;
                cnt++;
                if(cnt == 10){
                    cout << n * i << '\n';
                    return;
                }
            }
            tmp /= 10;
        }
    }
}

int main(){
    int t; cin >> t;
    for(int i = 1; i <= t; i++){
        fill(check, check + 10, 0);
        cin >> n;
        cout << "Case #" << i <<": ";
        if(n == 0){
            cout << "INSOMNIA" << '\n';
            continue;
        }
        sol();
    }
}