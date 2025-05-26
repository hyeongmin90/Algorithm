#include <bits/stdc++.h>

using namespace std;

priority_queue<long long, vector<long long>, greater<long long>> pq;

int main(){
    int n, m;
    cin >> n >> m;
    for(int i = 0; i < n; i++){
        int card; cin >> card;
        pq.push(card);
    }

    while(m--){
        long long a = pq.top();
        pq.pop();
        long long b = pq.top();
        pq.pop();
        pq.push(a + b);
        pq.push(a + b);
    }
    long long ans = 0;
    while(!pq.empty()){
        ans += pq.top();
        pq.pop();
    }
    cout << ans << '\n';
}