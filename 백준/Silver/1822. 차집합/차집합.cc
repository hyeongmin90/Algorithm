#include <bits/stdc++.h>

using namespace std;

set<int> s;

int main(){
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n, m;
    cin >> n >> m;
    for(int i = 0; i < n; i++){
        int num; cin >> num;
        s.insert(num);
    }
    for(int j = 0; j < m; j++){
        int num; 
        cin >> num;
        if(s.find(num) != s.end()){
            s.erase(num);
        }
    }
    cout << s.size() << '\n';
    for(auto x : s) cout << x << ' ';
}