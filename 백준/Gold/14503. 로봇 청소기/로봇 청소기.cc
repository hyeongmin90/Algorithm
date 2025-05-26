#include <iostream>
#include <algorithm>
#define X first
#define Y second

using namespace std;

int n, m, r, c, cnt;
int board[55][55];
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};
bool clean[55][55];
int dir;
pair<int, int> cur;
bool go;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    cin >> n >> m >> r >> c >> dir;
    cur = {r, c};
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> board[i][j];
        }
    }
    while (1)
    {
        go = false;
        if (!clean[cur.X][cur.Y]){
            clean[cur.X][cur.Y] = true;
            cnt++;
        }
        for (int i = 0; i < 4; i++)
        {
            int nx = cur.X + dx[i];
            int ny = cur.Y + dy[i];
            if (nx < 0 || nx >= n || ny < 0 || ny >= m)
                continue;
            if (clean[nx][ny] || board[nx][ny] == 1)
                continue;
            go = true; // 청소 되지 않은 칸 존재
        }
        if (go)
        {
            for (int i = 0; i < 4; i++)
            {
                dir -= 1; // 반시계 방향 회전
                if (dir < 0)
                    dir = 3;

                int nn = cur.X + dx[dir];
                int mm = cur.Y + dy[dir];
                if(board[nn][mm] == 1 || clean[nn][mm])continue;
                cur = {nn, mm}; // 현재 보는 방향으로 이동
                break;
            }
            continue;
        }
        int nn = cur.X + dx[(dir + 2) % 4];
        int mm = cur.Y + dy[(dir + 2) % 4];
        if (board[nn][mm] == 1) // 뒤로 이동 불가
            break;
        cur = {nn, mm}; // 뒤로 이동
    }
    cout << cnt;
    return 0;
}