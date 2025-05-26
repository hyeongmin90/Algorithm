#include <bits/stdc++.h>

using namespace std;

long long int color[500001];
long long int notprime[500001];

int main(){
    long long int n; cin >> n;
    if(n == 1){
        cout << 1 << '\n' << 1;
        return 0;
    }
    color[1] = 1;
    long long int Color = 2;
    for(long long int i = 2; i <= n; i++){
        if(!notprime[i]){
            color[i] = Color++;
            for(long long int j = i * i; j <= n; j += i){
                notprime[j] = 1;
                color[j] = color[i];
        }
        }
    }
    cout << Color - 1 << '\n';
    for(long long int i = 1; i <= n; i++)
        cout << color[i] << ' ';
}