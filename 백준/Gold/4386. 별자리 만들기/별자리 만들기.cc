#include <bits/stdc++.h>

using namespace std;

pair<double, double> arr[101];
bool vis[101];
vector<pair<double, int>> v[101];
priority_queue<pair<double, int>, vector<pair<double, int>>, greater<pair<double, int>>> pq;
double ans;

double func(pair<double, double> a, pair<double, double> b){
    return hypot(abs(a.first - b.first), abs(a.second - b.second));
}

int main(){
    ios::sync_with_stdio(0), cout.tie(0), cin.tie(0);
    int n; cin >> n;
    for(int i = 0; i < n; i++){
        double x, y;
        cin >> x >> y;
        arr[i] = {x, y};
    }

    for(int i = 1; i < n; i++){
        for(int j = 0; j < i; j++){
            double dis = func(arr[i], arr[j]);
            v[i].push_back({dis, j});
            v[j].push_back({dis, i});
        }
    }

    for(auto x : v[0]) pq.push(x);
    vis[0] = true;

    while(!pq.empty()){
        auto cur = pq.top();
        pq.pop();
        if(vis[cur.second]) continue;
        vis[cur.second] = true;
        for(auto x : v[cur.second]) pq.push(x);
        ans += cur.first;
    }

    cout << ans << '\n';
}