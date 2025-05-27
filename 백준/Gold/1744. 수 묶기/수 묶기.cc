//boj 1744

#include <bits/stdc++.h>

using namespace std;

priority_queue<int> pos;
priority_queue<int, vector<int>, greater<int>> neg;
int ans;

int main(){
    int n; cin >> n;
    for(int i = 0; i < n; i++){
        int num; cin >> num;
        (num > 0 ? pos.push(num) : neg.push(num));
    }
    
    while(pos.size() >= 2){
        int a = pos.top();
        pos.pop();
        int b = pos.top();
        pos.pop();

        if(a == 1 || b == 1){
            ans = ans + a + b;
            continue;
        }

        ans += a * b;
    }
    if(!pos.empty()) ans += pos.top();
    
    while(neg.size() >= 2){
        int a = neg.top();
        neg.pop();
        int b = neg.top();
        neg.pop();
        ans += a * b;
    }
    if(!neg.empty()) ans += neg.top();
    
    cout << ans << '\n';
}