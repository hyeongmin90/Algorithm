#include <bits/stdc++.h>

using namespace std;

priority_queue<int, vector<int>, greater<int>> pq;

int main(){
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n;
    cin >> n;
    for(int i = 0; i < n ; i++){
        for(int j = 0; j < n; j++){
            int num; cin >> num;
            pq.push(num);
        }
        
        while(pq.size() > n) pq.pop();
    }
    
    cout << pq.top() << '\n';
}