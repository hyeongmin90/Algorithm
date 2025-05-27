#include <bits/stdc++.h>

using namespace std;

pair<int, int> arr[1001];
stack<pair<int, int>> s;
int ans;

int main(){
    int n; cin >> n;
    for(int i = 0; i < n; i++){
        int l, h;
        cin >> l >> h;
        arr[i] = {l, h};
    }
    sort(arr, arr + n);
    for(int i = 0; i < n; i++){
        auto [nl, nh] = arr[i];
        while(!s.empty() && s.top().second <= nh){
            if(s.size() == 1){
                ans += (s.top().second * (nl - s.top().first));
            }
            s.pop();
        }
        s.push(arr[i]);
    }
    pair<int, int> pre;
    while(!s.empty()){
        if(s.size() == 1){
            ans += s.top().second;
            s.pop();
            continue;
        }
        pre = s.top();
        s.pop();
        ans += (pre.second * (pre.first - s.top().first));
    }
    cout << ans << '\n';
}