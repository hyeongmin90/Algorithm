#include <bits/stdc++.h>

using namespace std;

int trains[100001];
unordered_set<int> s;

int main(){
    int n, m;
    cin >> n >> m;
    for(int i = 0; i < m; i++){
        int order, a;
        cin >> order >> a;
        if(order == 1){
            int b;
            cin >> b;
            trains[a] |= (1 << (b - 1));
        }
        else if(order == 2){
            int b;
            cin >> b;
            trains[a] &= ~(1 << (b - 1));
        }
        else if(order == 3){
            trains[a] <<= 1;
            trains[a] &= (1 << 20) - 1;
        }
        else{
            trains[a] >>= 1;
        }
    }
    for(int i = 1; i <= n; i++){
        if(s.find(trains[i]) != s.end()) continue;
        s.insert(trains[i]);
    }
    cout << s.size() << '\n';
}