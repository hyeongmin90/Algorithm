#include <bits/stdc++.h>

using namespace std;

set<int> s;
pair<int, int> arr[101];
priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<tuple<int, int, int>>> pq;

int main(){
    int n, m;
    cin >> n >> m;
    for(int i = 1; i <= m; i++){
        int a; cin >> a;
        if(s.size() >= n && !arr[a].first){
            while(1){
                auto [cnt, order, num] = pq.top();
                pq.pop();
                if(arr[num].first != cnt)continue;
                arr[num] = {0, 0};
                s.erase(num);
                break;
            }
        }
        arr[a].first++;
        if (!arr[a].second) arr[a].second = i;
        s.insert(a);
        pq.push({arr[a].first, arr[a].second, a});
    }
    for(auto x : s) cout << x << ' ';
}