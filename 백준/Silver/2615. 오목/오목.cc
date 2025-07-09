#include <bits/stdc++.h>

using namespace std;

int board[20][20];
int dx[4] = {0, 1, 1, 1};
int dy[4] = {1, 0, 1, -1};

void func(){
    for(int i = 0; i < 19; i++){
        for(int j = 0; j < 19; j++){
            if(board[i][j] == 0) continue;
            int color = board[i][j];
            for(int dir = 0; dir < 4; dir++){
                int nx = i, ny = j;
                int cnt = 1;
                while(1){
                    nx += dx[dir];
                    ny += dy[dir];
                    if(nx < 0 || nx >= 19 || ny < 0 || ny >= 19) break;
                    if(board[nx][ny] != color) break;
                    cnt++;
                }
                if(cnt == 5){
                    int mx = i - dx[dir];
                    int my = j - dy[dir];
                    if((mx >= 0 || mx < 19 || my >= 0 || my < 19) && board[mx][my] == color)
                        continue;

                    cout << color << '\n';
                    int x = i + 1, y = j + 1;
                    if(dir == 3) cout << x + 4 << ' ' << y - 4 << '\n';
                    else cout << x << ' ' << y;
                    return;
                }
            }
        }
    }
    cout << 0 << '\n';
}

int main(){
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    for(int i = 0; i < 19; i++){
        for(int j = 0; j < 19; j++){
            cin >> board[i][j];
        }
    }
    func();
}