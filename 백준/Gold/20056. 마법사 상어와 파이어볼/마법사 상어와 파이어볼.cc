#include <bits/stdc++.h>

using namespace std;

struct fireball{
    int m, s, d;
};

int n, m, k;
vector<fireball> fireballs[51][51];
int dx[8] = {-1, -1, 0, 1, 1, 1, 0, -1};
int dy[8] = {0, 1, 1, 1, 0, -1, -1, -1};

int wrap(int a){
    return (a % n + n) % n;
}

pair<int, int> move(int x, int y, int s, int dir){
    int nx = x + (dx[dir]) * s;
    int ny = y + (dy[dir]) * s;
    return {wrap(nx), wrap(ny)};
}

void simulation(){
    vector<fireball> nxt[51][51];
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(fireballs[i][j].size() == 0) continue;
            for(auto cur : fireballs[i][j]){
                auto [m, s, d] = cur;
                auto [nx, ny] = move(i, j, s, d);
                nxt[nx][ny].push_back(cur);
            }
        }
    }

    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(nxt[i][j].size() < 2) continue;
            int sum_m = 0, sum_s = 0, cnt = nxt[i][j].size();
            vector<fireball> v;
            bool even = false, odd = false;
            for(auto cur : nxt[i][j]){
                auto [m, s, d] = cur;
                sum_m += m;
                sum_s += s;
                if(d % 2 == 0) even = true;
                else odd = true;
            }
            int k = !(even ^ odd);
            if(sum_m / 5 != 0){
                for(int dir = k; dir < 8; dir += 2)
                    v.push_back({sum_m / 5, sum_s / cnt, dir});
            }
            nxt[i][j] = v;
        }
    }
    swap(fireballs, nxt);
}


int main(){
    ios::sync_with_stdio(0), cin.tie(0);
    cin >> n >> m >> k;
    for(int i = 0; i < m; i++){
        int x, y, m, s, d;
        cin >> x >> y >> m >> s >> d;
        fireballs[x - 1][y - 1].push_back({m, s, d});
    }
    for(int i = 0; i < k; i++){
        simulation();
    }

    int ans = 0;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(fireballs[i][j].size() == 0) continue;
            for(auto [m, s, d] : fireballs[i][j])
                ans += m;
        }
    }

    cout << ans << '\n';
}