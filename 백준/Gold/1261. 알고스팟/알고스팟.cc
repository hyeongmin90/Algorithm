#include <bits/stdc++.h>
#define X first
#define Y second

using namespace std;

string board[101];
int cnt[101][101];
deque<pair<int, int>> dq;
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

int main(){
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n, m;
    cin >> m >> n;
    for(int i = 0; i < n; i++)
        cin >> board[i];
    
    for(int i = 0; i < n; i++)
        fill(cnt[i], cnt[i] + m, -1);
    
    dq.push_back({0, 0});
    cnt[0][0] = 0;
    while(!dq.empty()){
        auto cur = dq.front();
        dq.pop_front();
        for(int dir = 0; dir < 4; dir++){
            int nx = cur.X + dx[dir];
            int ny = cur.Y + dy[dir];
            if(nx < 0 || nx >= n || ny < 0 || ny >= m)continue;
            if(cnt[nx][ny] != -1)continue;
            if(board[nx][ny] == '1'){
                dq.push_back({nx, ny});
                cnt[nx][ny] = cnt[cur.X][cur.Y] + 1;
            }
            else {
                dq.push_front({nx, ny});
                cnt[nx][ny] = cnt[cur.X][cur.Y];
            }
        }
    }

    cout << cnt[n - 1][m - 1] << '\n';
}