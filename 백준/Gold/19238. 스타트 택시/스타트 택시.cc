#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
#include <cstring>
#include <tuple>

using namespace std;

struct p {
    int a, b, c;
};

struct pp
{
    int x1, y1, x2, y2;
};


int n, m, fuel;
int board[21][21];
bool vis[21][21];
queue<p> q;
int dx[4] = {-1, 0, 0, 1};
int dy[4] = {0, -1, 1, 0};
vector<pp> v;

bool compare(const p &a, const p &b){
    if(a.a != b.a) return a.a < b.a;
    if(a.b != b.b) return a.b < b.b;
    return a.c < b.c;
}

bool move(int target){
    if(target == -1) return 0;
    queue<p> q;
    memset(vis, 0, sizeof(vis));
    q.push({v[target].x1, v[target].y1});
    int cnt = 0;
    while(!q.empty()){
        p cur = q.front();
        int x = cur.a, y = cur.b, dist = cur.c;
        q.pop();
        if(fuel < 0) continue;
        for(int dir = 0; dir < 4; dir++){
            int nx = x + dx[dir];
            int ny = y + dy[dir];
            if(nx < 1 || nx > n || ny < 1 || ny > n) continue;
            if(board[nx][ny] == -1 || vis[nx][ny]) continue;
            if(nx == v[target].x2 && ny == v[target].y2){
                fuel -= dist + 1;
                if(fuel < 0) return 0;
                fuel += (dist + 1) * 2;
                return 1;
            }
            vis[nx][ny] = 1;
            q.push({nx, ny, dist + 1});
        }
    }
    return 0;
}

int search(int a, int b){
    queue<p> q;
    memset(vis, 0, sizeof(vis));
    vector<p> cust;
    q.push({a, b, 0});
    while(!q.empty()){
        p cur = q.front();
        int x = cur.a, y = cur.b, dist = cur.c;
        q.pop();
        if(board[x][y] >= 1) cust.push_back({dist, x, y});

        for(int dir = 0; dir < 4; dir++){
            int nx = x + dx[dir];
            int ny = y + dy[dir];
            if(nx < 1 || nx > n || ny < 1 || ny > n) continue;
            if(board[nx][ny] == -1 || vis[nx][ny]) continue;            
            vis[nx][ny] = 1;
            q.push({nx, ny, dist + 1});
        }
    }
    sort(cust.begin(), cust.end(), compare);
    if(!cust.empty()){
        fuel -= cust[0].a;
        if(fuel < 0) return -1;
        int num = board[cust[0].b][cust[0].c];
        board[cust[0].b][cust[0].c] = 0;
        return num;
    }
    return -1;
}

int main(){
    cin >> n >> m >> fuel;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            int a; cin >> a;
            board[i][j] = (a == 1 ? -1 : a);
        }
    }
    v.push_back({-1, -1});
    int x, y;
    cin >> x >> y;
    for(int i = 1; i <= m; i++){
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        board[x1][y1] = i;
        v.push_back({x1, y1, x2, y2});
    }

    for(int i = 0; i < m; i++){
        int a = search(x, y);
        if(!move(a)){
            cout << -1 << '\n';
            return 0;
        }
        x = v[a].x2;
        y = v[a].y2;
    }
    cout << fuel << '\n';
}