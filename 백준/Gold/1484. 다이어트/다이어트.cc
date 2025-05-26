#include <bits/stdc++.h>

using namespace std;

vector<int> v;

int main(){
    int n;
    cin >> n;
    int j = 1;
    for(int i = 1; i < 100000; i++){
        while(j * j - i * i < n && j < 100000) j++;
        if(j * j - i * i == n)v.push_back(j);
    }
    if(v.empty()) cout << -1;
    else for(auto x : v) cout << x << '\n';
}