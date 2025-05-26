#include <bits/stdc++.h>

using namespace std;

string board[51];

int main(){
    int n, m, ans = 1;
    cin >> n >> m;
    for(int i = 0; i < n; i++)
        cin >> board[i];
    
    for(int k = 1; k <= min(n, m); k++){
        for(int i = 0; i <= n - k; i++){
            for(int j = 0; j <= m - k; j++){
                if(board[i][j] != board[i + k - 1][j]) continue;
                if(board[i][j] != board[i][j + k -1]) continue;
                if(board[i][j] != board[i + k - 1][j + k -1]) continue;
                ans = k * k;
            }   
        }
    }
    cout << ans << '\n';
}