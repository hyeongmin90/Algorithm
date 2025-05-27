#include <bits/stdc++.h>

using namespace std;

priority_queue<int, vector<int>, greater<int>> pq;

int main(){
    int n; cin >> n;
    while(n--){
        int num; cin >> num;
        pq.push(num);
    }
    int cnt = 0;
    while(pq.size() > 1){
        int card = 0;
        card += pq.top();
        pq.pop();
        card += pq.top();
        pq.pop();
        cnt += card;
        pq.push(card);
    }
    cout << cnt << '\n';
}