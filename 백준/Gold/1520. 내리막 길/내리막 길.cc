#include <bits/stdc++.h>

using namespace std;

int n, m;
int a[501][501];
int dp[501][501];
int cnt;
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};



int dfs(int x, int y)
{
    if (x == m - 1 && y == n - 1)
        return 1;
    if(dp[x][y] != -1)
        return dp[x][y];

    int &cnt = dp[x][y];
    cnt = 0;

    for (int dir = 0; dir < 4; dir++)
    {
        int nx = x + dx[dir];
        int ny = y + dy[dir];
        if (nx < 0 || nx >= m || ny < 0 || ny >= n)
            continue;
        if (a[nx][ny] < a[x][y]){
            cnt += dfs(nx, ny);
        }
    }
    return cnt;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    cin >> m >> n;
    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++){
            cin >> a[i][j];
            dp[i][j] = -1;
        }

    cout << dfs(0, 0);
    /*
    cout << '\n';
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << dp[i][j] << ' ';
        }
        cout << '\n';
    }
    */

    return 0;
}