#include <bits/stdc++.h>
#define X first
#define Y second
#define ll long long

using namespace std;

ll INF = 0x3f3f3f3f3f;
vector<pair<ll, ll>> v[100005];
ll dist[100005];
vector<ll> d;
priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, greater<pair<ll, ll>>>pq;

int main(){
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n, m, k;
    cin >> n >> m >> k;
    for(int i = 0; i < m; i++){
        int s, e, t;
        cin >> s >> e >> t;
        //역방향으로 입력 받음
        v[e].push_back({t, s});
    }
    for(int i = 0; i < k; i++){
        int a; cin >> a;
        d.push_back(a);
        //임의의 도시 n + 1 에서 면접장까지의 (가중치 0) 경로 생성
        v[n + 1].push_back({0, a});
    }
    fill(dist, dist + n + 1, INF);
    //n + 1 번째 도시에서 시작
    pq.push({0, n + 1});
    while(!pq.empty()){
        auto cur = pq.top();
        pq.pop();
        if(dist[cur.Y] != cur.X)continue;
        for(auto nxt : v[cur.Y]){
            if(dist[nxt.Y] < dist[cur.Y] + nxt.X) continue;
            dist[nxt.Y] = dist[cur.Y] + nxt.X;
            pq.push({dist[nxt.Y], nxt.Y});
        }
    }
    ll MAXT, MAXC;
    for(int i = 1; i <= n; i++){
        if(MAXT < dist[i]){
            MAXT = dist[i];
            MAXC = i;
        }
    }
    cout << MAXC << '\n' << MAXT << '\n';

    
    

}