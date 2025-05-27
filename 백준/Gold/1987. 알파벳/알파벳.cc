#include <bits/stdc++.h>

using namespace std;

string board[21];
bool vis[26];
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
int n, m, ans;

void dfs(int depth, int x, int y){
    ans = max(ans, depth);
    for(int i = 0; i < 4; i++){
        int nx = x + dx[i];
        int ny = y + dy[i];
        if(nx < 0 || nx >= n || ny < 0 || ny >= m)continue;
        if(vis[board[nx][ny] - 'A'])continue;
        vis[board[nx][ny] - 'A'] = 1;
        dfs(depth + 1, nx, ny);
        vis[board[nx][ny] - 'A'] = 0;
    }
}

int main(){
    cin >> n >> m;
    for(int i = 0; i < n; i++)
        cin >> board[i];
    
    vis[board[0][0] - 'A'] = 1;
    dfs(1, 0, 0);
    cout << ans << '\n';
}