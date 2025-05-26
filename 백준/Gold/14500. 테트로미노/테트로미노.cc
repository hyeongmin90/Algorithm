#include <iostream>
#include <algorithm>
#include <queue>
#include <tuple>
#define X first
#define Y second

using namespace std;

int ans;
int board[505][505];
int n, m;
// 1, 2, 3, 3-2, 4, 4-2, 5 도형;
pair<int, int> rc[7] = {{1, 4}, {2, 2}, {3, 2}, {3, 2}, {3, 2}, {3, 2}, {2, 3}};
int block[7][4][4][4];

void setting()
{
    for (int k = 0; k < 7; k++)
    { // 블럭
        int x, y;
        tie(x, y) = rc[k];
        for (int i = 0; i < x; i++)
            for (int j = 0; j < y; j++)
                block[k][0][i][j] = 1;

        if (k == 2)
        {
            block[k][0][0][1] = 0;
            block[k][0][1][1] = 0;
        }
        else if (k == 3)
        {
            block[k][0][0][0] = 0;
            block[k][0][1][0] = 0;
        }
        else if (k == 4)
        {
            block[k][0][0][1] = 0;
            block[k][0][2][0] = 0;
        }
        else if (k == 5)
        {
            block[k][0][0][0] = 0;
            block[k][0][2][1] = 0;
        }
        else if (k == 6)
        {
            block[k][0][1][0] = 0;
            block[k][0][1][2] = 0;
        }

        for (int i = 0; i < y; i++)
            for (int j = 0; j < x; j++)
                block[k][1][i][j] = block[k][0][x - 1 - j][i];

        for (int i = 0; i < x; i++)
            for (int j = 0; j < y; j++)
                block[k][2][i][j] = block[k][1][y - 1 - j][i];

        for (int i = 0; i < y; i++)
            for (int j = 0; j < x; j++)
                block[k][3][i][j] = block[k][2][x - 1 - j][i];
    }
}

void check(int x, int y, int k, int dir)
{
    int nn = rc[k].X;
    int mm = rc[k].Y;
    int tmp = 0;
    if (dir % 2 == 1)
        swap(nn, mm);
    for (int i = 0; i < nn; i++)
    {
        for (int j = 0; j < mm; j++)
        {
            if(block[k][dir][i][j] == 1){
                tmp += board[i + x][j + y];
            }
        }
    }
    ans = max(ans, tmp);
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    cin >> n >> m;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cin >> board[i][j];
    setting();
    for (int k = 0; k < 7; k++) // 블록
    {
        for (int dir = 0; dir < 4; dir++) // 회전
        {
            for (int i = 0; i < n; i++)
            {
                for (int j = 0; j < m; j++)
                {
                    check(i, j, k, dir);
                }
            }
        }
    }
    cout << ans;
    return 0;
}