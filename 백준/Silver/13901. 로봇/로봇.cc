#include <bits/stdc++.h>

using namespace std;

int board[1002][1002];
bool vis[1002][1002];
int dist[4];
int dx[5] = {0, -1, 1, 0, 0};
int dy[5] = {0, 0, 0, -1, 1};
int r, c, k;
pair<int, int> cur;

int main()
{
    cin >> r >> c >> k;
    while (k--)
    {
        int x, y;
        cin >> x >> y;
        board[x][y] = -1;
    }
    cin >> cur.first >> cur.second;
    vis[cur.first][cur.second] = 1;
    for (int i = 0; i < 4; i++)
        cin >> dist[i];
    
    int i = 0;
    int check = 0;
    while (check < 4)
    {
        int nx = cur.first + dx[dist[i]];
        int ny = cur.second + dy[dist[i]];
        if (nx < 0 || nx >= r || ny < 0 || ny >= c || vis[nx][ny] || board[nx][ny] == -1){
            i = (i + 1) % 4;
            check++;
            continue;
        }
        cur = {nx, ny};
        vis[nx][ny] = 1;
        check = 0;
    }
    
    cout << cur.first << ' ' << cur.second;

}