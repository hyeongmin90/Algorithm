#include <bits/stdc++.h>

using namespace std;

struct l
{
    int x;
    int y;
    int z;
};

int n, ans;
vector<pair<int, int>> v[3], vv;
priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
l arr[100001];
bool vis[100001];
queue<pair<int, int>> q;


int main(){
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> n;
for(int i = 0; i < n; i++){
    int x, y, z;
    cin >> x >> y >> z;
    v[0].push_back({x, i});
    v[1].push_back({y, i});
    v[2].push_back({z, i});
}

    sort(v[0].begin(), v[0].end());
    sort(v[1].begin(), v[1].end());
    sort(v[2].begin(), v[2].end());

    for(int i = 0; i < n; i++){
        arr[v[0][i].second].x = i;
        arr[v[1][i].second].y = i;
        arr[v[2][i].second].z = i;
    }

    q.push({0, arr[0].x});
    q.push({1, arr[0].y});
    q.push({2, arr[0].z});
    vis[0] = 1;
    for(int i = 0; i < n - 1; i++){
        while(!q.empty()){
            auto [x, y] = q.front();
           q.pop();
            for(auto ny : {y + 1, y - 1}){
                if(ny < 0 || ny >= n)continue;
                if(vis[v[x][ny].second])continue;
                pq.push({abs(v[x][y].first - v[x][ny].first), v[x][ny].second});
            }
        }
        while(vis[pq.top().second]) pq.pop();
        auto [cost, nxt] = pq.top();
        pq.pop();
        vis[nxt] = 1;
        ans += cost;
        q.push({0, arr[nxt].x});
        q.push({1, arr[nxt].y});
        q.push({2, arr[nxt].z});
    }
    

    cout << ans << '\n';
}