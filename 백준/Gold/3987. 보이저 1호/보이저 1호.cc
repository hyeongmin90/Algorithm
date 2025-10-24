#include <bits/stdc++.h>

using namespace std;

int n, m;
string board[501];
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};
char t[4] = {'U', 'R', 'D', 'L'};

struct p
{
    int x, y, d;
};

queue<p> q;

bool OOB(int x, int y){
    return (x < 0 || x >= n || y < 0 || y >= m);
}

int directionChange(int dir, char a){
    if(a == '/'){
        if(dir % 2 == 0) return dir + 1;
        return dir - 1;
    }
    else{
        if(dir == 0) return 3;
        if(dir == 1) return 2;
        if(dir == 2) return 1;
        return 0;
    }
    return -1;
}

int simulation(int a, int b, int d){
    q.push({a, b, d});
    int cnt = 1;

    while(!q.empty()){
        auto cur = q.front();
        int x = cur.x, y = cur.y, dir = cur.d;
        q.pop();
        int nx = x + dx[dir];
        int ny = y + dy[dir];
        if(OOB(nx, ny) || board[nx][ny] == 'C') continue;
        if(board[nx][ny] == '/' || board[nx][ny] == '\\')
            dir = directionChange(dir, board[nx][ny]);
        if(nx == a && ny == b && dir == d){
            return -1;
        }
        cnt++;
        q.push({nx, ny, dir});
    }
    return cnt;
}

int main(){
    ios::sync_with_stdio(0), cout.tie(0), cin.tie(0);
    cin >> n >> m;
    for(int i = 0; i < n ; i++){
        cin >> board[i];
    }
    int x, y, ans = 0, d;
    cin >> x >> y;
    for(int dir = 0; dir < 4; dir++){
        int tmp = simulation(x - 1, y - 1, dir);
        if(tmp == -1){
            cout << t[dir] << '\n' << "Voyager";
            return 0;
        }
        if(ans < tmp){
            ans = tmp;
            d = dir;
        }
    }
    cout << t[d] << '\n' << ans;
}