#include <bits/stdc++.h>

using namespace std;

map<int, int> m;
map<int, int> order;

bool cmp(pair<int, int> a, pair<int, int> b){
    if(a.second == b.second) return order[a.first] < order[b.first];
    return a.second > b.second;
}

int main(){
    int n, c;
    cin >> n >> c;
    for(int i = 1; i <= n; i++){
        int a;
        cin >> a;
        m[a]++;
        if(order[a] == 0) order[a] = i;
    }
    vector<pair<int, int>> v(m.begin(), m.end());
    sort(v.begin(), v.end(), cmp);
    
    for(auto x : v){
        for(int i = 0; i < x.second; i++){
            cout << x.first << ' ';
        }
    }
    
}