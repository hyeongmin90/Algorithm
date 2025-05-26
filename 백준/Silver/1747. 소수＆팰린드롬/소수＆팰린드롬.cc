#include <bits/stdc++.h>
#define MAXN 1003001

using namespace std;

bool isprime[MAXN];

bool ispalindrome(int n){
    string num = to_string(n);
    string rev = num;
    reverse(rev.begin(), rev.end());
    if(num == rev) return true;
    return false;
}

int main(){
    int n; cin >> n;

    isprime[0] = 1;
    isprime[1] = 1;

    for(int i = 2; i * i <= MAXN; i++){
        if(isprime[i])continue;
        for(int j = i * i; j <= MAXN; j += i){
            isprime[j] = 1;
        }
    }

    for(int i = n; i <= MAXN; i++)
        if(!isprime[i] && ispalindrome(i)){
            cout << i << '\n';
            break;
        }
        
}