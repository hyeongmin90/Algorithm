#include <bits/stdc++.h>

using namespace std;

struct l
{
    int r, c, s;
};

l spin[7];
int board[51][51];
int arr[7];
int n, m, k, ans = 0x7fffffff;
bool vis[7];

void Spin(int (&matrix)[51][51], int r, int c, int s){
    r--;
    c--;
    int top = r - s;
    int left = c - s;
    int bottom = r + s;
    int right = c + s;

    int temp = matrix[top][left];

    for (int i = top; i < bottom; ++i) matrix[i][left] = matrix[i + 1][left];
    for (int i = left; i < right; ++i) matrix[bottom][i] = matrix[bottom][i + 1];
    for (int i = bottom; i > top; --i) matrix[i][right] = matrix[i - 1][right];
    for (int i = right; i > left; --i) matrix[top][i] = matrix[top][i - 1];

    matrix[top][left + 1] = temp;
}

void dfs(int depth){
    if(depth == k){
        int matrix[51][51] = {};
        memcpy(matrix, board, sizeof(board));

        for(int i = 0; i < k; i++){
            auto [r, c, s] = spin[arr[i]];
            for(int j = s; j >= 1; j--){
                Spin(matrix, r, c, j);
            }
        }
    
        for(int i = 0; i < n; i++){
            int tmp = 0;
            for(int j = 0; j < m; j++){
                tmp += matrix[i][j];
            }
            ans = min(ans, tmp);
        }   
        return;
    }
    for(int i = 0; i < k; i++){
        if(vis[i]) continue;
        vis[i] = true;
        arr[depth] = i;
        dfs(depth + 1);
        vis[i] = false;
    }
}

int main(){
    cin >> n >> m >> k;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin >> board[i][j];
        }
    }
    for(int i = 0; i < k; i++){
        int r, c, s;
        cin >> r >> c >> s;
        spin[i] = {r, c, s};
    }
    dfs(0);
    cout << ans << '\n';
}