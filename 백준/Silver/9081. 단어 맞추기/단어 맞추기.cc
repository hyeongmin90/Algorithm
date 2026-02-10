#include <bits/stdc++.h>

using namespace std;

int main(){
    ios::sync_with_stdio(0), cin.tie(0);
    int n;
    cin >> n;
    for(int i = 0; i < n; i++){
        vector<char> v;
        string str;
        cin >> str;
        for(int j = 0; j < str.size(); j++){
            v.push_back(str[j]);
        }
        if(next_permutation(v.begin(), v.end())){
            for(auto c : v) cout << c;
        }
        else cout << str;
        cout << '\n';
    }
}