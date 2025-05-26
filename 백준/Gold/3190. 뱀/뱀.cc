#include <iostream>
#include <algorithm>
#include <deque>
#define X first
#define Y second

using namespace std;
int n, k, l;
int board[105][105];
int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};
deque<pair<int, int>> d;
deque<pair<int, int>> dd;
int cnt;
int dir;

bool OOB(int x, int y)
{
    if (x < 0 || x >= n || y < 0 || y >= n)
        return true;
    return false;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    cin >> n >> k;
    // 사과
    for (int i = 0; i < k; i++)
    {
        int x, y;
        cin >> x >> y;
        board[x - 1][y - 1] = 1;
    }
    cin >> l;
    d.push_back({0, 0});
    board[0][0] = 2;
    // 이동방향
    for (int i = 0; i < l; i++)
    {
        int t;
        char turn;
        cin >> t >> turn;
        if (turn == 'D')
            dd.push_back({t, 1});
        else
        {
            dd.push_back({t, -1});
        }
    }
    while (1)
    {
        if (cnt == dd.front().X)
        {
            dir = (dir + dd.front().Y) % 4;
            if (dir < 0)
                dir = 3;
            dd.pop_front();
        }
        cnt++;
        auto cur = d.front();
        auto tail = d.back();
        int nx = cur.X + dx[dir];
        int ny = cur.Y + dy[dir];
        if (OOB(nx, ny) || board[nx][ny] == 2) // 종료
        {
            cout << cnt;
            return 0;
        }
        if (board[nx][ny] != 1) // 일반 이동
        {
            board[tail.X][tail.Y] = 0;
            d.pop_back();
        }
        d.push_front({nx, ny});
        board[nx][ny] = 2;
    }

    return 0;
}