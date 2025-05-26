#include<bits/stdc++.h>

using namespace std;

int main(){
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n; cin >> n;
    int S = 0;
    while(n--){
        string str;
        int x;
        cin >> str;
        if(str == "add"){
            cin >> x;
            S |= (1 << x);
        }
        if(str == "remove"){
            cin >> x;
            S &= ~(1 << x);
        }
        if(str == "check"){
            cin >> x;
            if(S & (1 << x)) cout << 1 << '\n';
            else cout << 0 << '\n';
        }
        if(str == "toggle"){
            cin >> x;
            S ^= (1 << x);
        }
        if(str == "all") S = (1 << 21) - 1;
        if(str == "empty") S = 0;
    }
}