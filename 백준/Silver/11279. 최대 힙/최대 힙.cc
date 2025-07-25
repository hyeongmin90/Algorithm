#include <bits/stdc++.h>

using namespace std;

priority_queue<int> pq;

int main(){
    ios::sync_with_stdio(0), cout.tie(0), cin.tie(0);
    int n; cin >> n;
    for(int i = 0; i < n; i++){
        int num; cin >> num;
        if(!num){
            if(!pq.size()) cout << 0 << '\n';
            else {
                cout << pq.top() << '\n';
                pq.pop();
            }
            continue;
        }
        pq.push(num);
    }
}