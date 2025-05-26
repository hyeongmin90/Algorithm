#include <iostream>
#include <algorithm>
#include <queue>
#include <cmath>
#define X first
#define Y second

using namespace std;

int n;
int board[22][22];
pair<int, int> shark;
pair<int, int> sharksize = {2, 0};
int dx[4] = {-1, 0, 0, 1};
int dy[4] = {0, -1, 1, 0};
int ans;
bool check;


void func()
{
    queue<pair<int, int>> q;
    pair<int, int> nxt = {22, 22};
    int nxt_d = 0;
    q.push(shark);
    bool visit[22][22] = {false};
    visit[shark.X][shark.Y] = true;
    int dist[22][22] = {};
    bool find = false;
    while (!q.empty())
    {
        auto cur = q.front();
        q.pop();
        if(find && dist[cur.X][cur.Y] >= nxt_d){
            board[nxt.X][nxt.Y] = 0;
            ans += nxt_d;
            shark = (nxt);
            sharksize.Y++;
            if(sharksize.X == sharksize.Y){
                sharksize.X++;
                sharksize.Y = 0;
            }
            return;
        }
        for (int i = 0; i < 4; i++)
        {
            int nx = cur.X + dx[i];
            int ny = cur.Y + dy[i];
            if (nx < 0 || nx >= n || ny < 0 || ny >= n)
                continue;
            if (visit[nx][ny] || board[nx][ny] > sharksize.X)
                continue;
            if (board[nx][ny] != 0 && board[nx][ny] < sharksize.X)
            {
                find = true;
                nxt_d = dist[cur.X][cur.Y] + 1;
                
                if (nxt.X > nx)
                {
                    nxt = {nx, ny};
                }
                else if (nxt.X == nx)
                {
                    if (nxt.Y > ny)
                        nxt = {nx, ny};
                }
                visit[nx][ny] = true;
                continue;
            }
            visit[nx][ny] = true;
            q.push({nx, ny});
            dist[nx][ny] = dist[cur.X][cur.Y] + 1;
        }
    }
    if(find){
        board[nxt.X][nxt.Y] = 0;
        ans += nxt_d;
        shark = (nxt);
        sharksize.Y++;
        if (sharksize.X == sharksize.Y)
        {
            sharksize.X++;
            sharksize.Y = 0;
        }
        return;
    }
    check = true;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    cin >> n;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
        {
            cin >> board[i][j];
            if (board[i][j] == 9){
                shark = {i, j};
                board[i][j] = 0;
            }
        }
    while (!check)
    {
        func();
    }
    cout << ans;
    return 0;
}
