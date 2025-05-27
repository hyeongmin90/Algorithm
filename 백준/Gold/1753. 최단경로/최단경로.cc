#include <bits/stdc++.h>
#define X first
#define Y second 

using namespace std;

int INF = 0x3f3f3f3f;
vector<pair<int, int>> V[20001];
int arr[20001];
priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

int main(){
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int nd, e, st;
    cin >> nd >> e >> st;
    fill(arr, arr + nd + 1, INF);
    for(int i = 0; i < e; i++){
        int u, v, w;
        cin >> u >> v >> w;
        V[u].push_back({w, v});
    }
    arr[st] = 0;
    pq.push({0, st});
    while(!pq.empty()){
        auto cur = pq.top();
        pq.pop();
        if(arr[cur.Y] != cur.X)continue;
        for(auto nxt : V[cur.Y]){
            if(arr[nxt.Y] <= arr[cur.Y] + nxt.X) continue;
            arr[nxt.Y] = arr[cur.Y] + nxt.X;
            pq.push({arr[nxt.Y], nxt.Y});
        }
    }
    for(int i = 1; i <= nd; i++){
        if(arr[i] == INF)cout << "INF\n";
        else cout << arr[i] << '\n';
    }
}