#include <iostream>
#include <algorithm>

using namespace std;

struct shark
{
    int speed;
    int dir;
    int size;
};

int R, C, m;
shark board[102][102];
int dx[5] = {0, -1, 1, 0, 0};
int dy[5] = {0, 0, 0, 1, -1};

void shark_move()
{
    shark tmp[102][102] = {};
    for (int i = 0; i < R; i++)
    {
        for (int j = 0; j < C; j++)
        {
            if (board[i][j].size == 0)
                continue;
            int num = 0;
            int nx = i, ny = j;

            if (board[i][j].dir > 2)
            { // 좌우이동
                ny = board[i][j].speed;
                if (board[i][j].dir == 3)
                { // 오른쪽으로 이동
                    if ((j + ny) < C)
                    {
                        ny += j;
                    }
                    else
                    {
                        int n = C - 1;
                        int tmp = n - j;
                        ny = ny - tmp;
                        int num = ny / n;
                        int num2 = ny % n;
                        if (num % 2 == 0)
                        {
                            ny = n - num2;
                            board[i][j].dir = 4;
                        }
                        else
                        {
                            ny = num2;
                        }
                    }
                }
                else // 왼쪽
                {
                    if ((j - ny) >= 0)
                    {
                        ny = j - ny;
                    }
                    else
                    {
                        int n = C - 1;
                        ny = ny - j;
                        int num = ny / n;
                        int num2 = ny % n;
                        if (num % 2 == 0)
                        {
                            ny = num2;
                            board[i][j].dir = 3;
                        }
                        else
                        {
                            ny = n - num2;
                        }
                    }
                }
            }
            else
            { // 상하이동
                nx = board[i][j].speed;
                if (board[i][j].dir == 2)
                { // 아래로 이동
                    if ((i + nx) < R)
                    {
                        nx = i + nx;
                    }
                    else
                    {
                        int n = R - 1;
                        int tmp = n - i;
                        nx = nx - tmp;
                        int num = nx / n;
                        int num2 = nx % n;
                        if (num % 2 == 0)
                        {
                            nx = n - num2;
                            board[i][j].dir = 1;
                        }
                        else
                        {
                            nx = num2;
                        }
                    }
                }
                else // 위
                {
                    if ((i - nx) >= 0)
                    {
                        nx = i - nx;
                    }
                    else
                    {
                        int n = R - 1;
                        nx = nx - i;
                        int num = nx / n;
                        int num2 = nx % n;
                        if (num % 2 == 0)
                        {
                            nx = num2;
                            board[i][j].dir = 2;
                        }
                        else
                        {
                            nx = n - num2;
                        }
                    }
                }
            }

            if (tmp[nx][ny].size != 0)
            {
                if (tmp[nx][ny].size < board[i][j].size)
                {
                    tmp[nx][ny] = board[i][j];
                }
            }
            else
                tmp[nx][ny] = board[i][j];
        }
    }

    for (int i = 0; i < R; i++)
    {
        for (int j = 0; j < C; j++)
        {
            board[i][j] = tmp[i][j];
        }
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    cin >> R >> C >> m;
    while (m--)
    {
        int r, c, s, d, z;
        cin >> r >> c >> s >> d >> z;
        board[r - 1][c - 1] = {s, d, z};
    }
    int ans = 0;
    /*
    cout << "before move\n";
    for (int i = 0; i < R; i++)
    {
        for (int j = 0; j < C; j++)
        {
            cout << board[i][j].speed << board[i][j].dir << board[i][j].size << ' ';
        }
        cout << '\n';
    }

    // shark_move();
    */
    for (int j = 0; j < C; j++)
    {
        for (int i = 0; i < R; i++)
        {
            if (board[i][j].size == 0)
                continue;
            ans += board[i][j].size;
            // cout << "catch!" << i << j << '\n';
            board[i][j] = {0, 0, 0};
            break;
        }
        shark_move();
        /*
                cout << "after move\n";
                for (int i = 0; i < R; i++)
                {
                    for (int j = 0; j < C; j++)
                    {
                        cout << board[i][j].speed << board[i][j].dir << board[i][j].size << ' ';
                    }
                    cout << '\n';
                }
                */
    }
    cout << ans;

    return 0;
}