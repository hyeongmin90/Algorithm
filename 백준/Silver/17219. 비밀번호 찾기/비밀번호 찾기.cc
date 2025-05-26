#include <bits/stdc++.h>

using namespace std;

map<string, string> M;

int main(){
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n, m;
    cin >> n >> m;
    for(int i = 0; i < n; i++){
        string add, pass;
        cin >> add >> pass;
        M[add] = pass;
    }
    for(int i = 0; i < m; i++){
        string add;
        cin >> add;
        cout << M[add] << '\n';
    }
}