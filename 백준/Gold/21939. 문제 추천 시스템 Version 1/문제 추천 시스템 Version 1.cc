#include <bits/stdc++.h>

using namespace std;

multiset<pair<int,int>> ms; // (난이도, 문제)
map<int, int> ma; // 문제 = 난이도

int main(){
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n; cin >> n;
    while(n--){
        int p, l;
        cin >> p >> l;
        ms.insert({l, p});
        ma[p] = l;
    }
    int m; cin >> m;
    while(m--){
        string cmd;
        cin >> cmd;
        if(cmd == "add"){
            int p, l;
            cin >> p >> l;
            ms.insert({l, p});
            ma[p] = l;
        }
        else if(cmd == "recommend"){
           int num; cin >> num;
           if(num == 1) cout << prev(ms.end())->second << '\n';
           else cout << ms.begin()->second << '\n';
        }
        else{
            int p; cin >> p;
            ms.erase({ma[p], p});
            ma.erase(p);
        }
    }
}
