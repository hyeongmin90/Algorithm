#include <bits/stdc++.h>

using namespace std;

class cmp
{
public:
    bool operator() (pair<int, int> a, pair<int, int> b) {
        if(a.first != b.first) return a.first > b.first;
        return a.second < b.second;
    }
};

priority_queue<pair<int, int>, vector<pair<int, int>>, cmp> pq;
priority_queue<int, vector<int>, greater<int>> pq2;

int main(){
    ios::sync_with_stdio(0), cout.tie(0), cin.tie(0);
    int n; cin >> n;
    for(int i = 0; i < n; i++){
        int dl, c;
        cin >> dl >> c;
        pq.push({dl, c});
    }

    int i = 1, ans = 0;
    while(pq.size()){
        if(pq.top().first >= i){
            ans += pq.top().second;
            pq2.push(pq.top().second);
            pq.pop();
            i++;
            continue;
        }
        if(pq2.size() == pq.top().first && pq2.top() < pq.top().second){
            ans -= pq2.top();
            ans += pq.top().second;
            pq2.pop();
            pq2.push(pq.top().second);
        }
        pq.pop();
    }

    cout << ans << '\n';
}