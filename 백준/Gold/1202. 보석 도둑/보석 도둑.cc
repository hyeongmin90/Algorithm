#include <bits/stdc++.h>

using namespace std;

vector<int> bags;
priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> arr;
priority_queue<int> pq;
long long ans;

int main(){
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n, k;
    cin >> n >> k;
    for(int i = 0; i < n; i++){
        int m, v;
        cin >> m >> v;
        arr.push({m, v});
    }
    for(int i = 0; i < k; i++){
        int bag;
        cin >> bag;
        bags.push_back(bag);
    }
    sort(bags.begin(), bags.end());

    for(int i = 0; i < k; i++){
        int limit = bags[i];
        while(!arr.empty() && arr.top().first <= limit){
            pq.push(arr.top().second);
            arr.pop();
        }
        if(!pq.empty()){
            ans += pq.top();
            pq.pop();   
        }
    }
    cout << ans << '\n';
}