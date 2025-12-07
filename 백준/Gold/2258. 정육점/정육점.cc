#include <bits/stdc++.h>

using namespace std;

vector<pair<int, int>> v;
int n, m;

bool compare(const pair<int, int> &a, const pair<int, int> &b){
    if (a.first != b.first) return a.first < b.first;
    return a.second > b.second;
}

int func(){
    int cur_price = 0, total_amount = 0, pre_price = 0;
    for(auto x : v){
        int price = x.first;
        int amount = x.second;
        
        if (total_amount >= m){
            if(pre_price == price) continue;
            return min(cur_price, price);
        }

        if (pre_price < price) {
            pre_price = price;
            cur_price = price;
        }
        else cur_price += price;

        total_amount += amount;
    }
    if (total_amount >= m) return cur_price;
    return -1;
}

int main(){
    cin >> n >> m;
    for(int i = 0; i < n; i++){
        int a, b;
        cin >> a >> b;
        v.push_back({b, a});
    }
    sort(v.begin(), v.end(), compare);
    cout << func() << '\n';
}