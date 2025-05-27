#include <bits/stdc++.h>

using namespace std;

int arr[101];
unordered_map<int, queue<int>> m; //[data] = {idx}
priority_queue<pair<int, int>> pq; //<idx, data>
bool vis[101];
int ans;

int main(){
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n, k;
    cin >> n >> k;
    for(int i = 0; i < k; i++){
        int num;
        cin >> arr[i];
        m[arr[i]].push(i);
    }
    
    for(auto& x : m) x.second.pop();
    
    int cnt  = 0;
    for(int i = 0; i < k; i++){
        if(cnt < n){
            if(!vis[arr[i]])cnt++;
            if(m[arr[i]].empty()) pq.push({1000, arr[i]});
            else pq.push({m[arr[i]].front(), arr[i]});
            if(!m[arr[i]].empty()) m[arr[i]].pop();
            vis[arr[i]] = 1;
            continue;
        }
        if(!vis[arr[i]]){
            ans++;
            vis[pq.top().second] = 0;
            pq.pop();
            vis[arr[i]] = 1;
        }
        if(m[arr[i]].empty()) pq.push({1000, arr[i]});
        else pq.push({m[arr[i]].front(), arr[i]});
        if(!m[arr[i]].empty()) m[arr[i]].pop();
    }
    cout << ans << '\n';

}