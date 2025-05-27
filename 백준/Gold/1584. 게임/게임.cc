#include <bits/stdc++.h>
 
using namespace std;

struct qq
{
    int x;
    int y;
    int cost;
};

int board[501][501];
int danger[501][501];
queue<qq> q;
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

void painting(int x1, int y1, int x2, int y2, int k){
    int xmin = min(x1, x2);
    int xmax = max(x1, x2);
    int ymin = min(y1, y2);
    int ymax = max(y1, y2);
    for(int i = xmin; i <= xmax; i++)
        for(int j = ymin; j <= ymax; j++)
            danger[i][j] = k;
        
}

int main(){
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n; cin >> n;
    for(int i = 0; i <= 500; i++)
        fill(board[i], board[i] + 501, -1);

    while(n--){
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        painting(x1, y1, x2, y2, 1);
    }
    cin >> n;
    while(n--){
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        painting(x1, y1, x2, y2, 2);
    }
    q.push({0, 0, 0});
    board[0][0] = 0;
    while(!q.empty()){
        auto cur = q.front();
        q.pop();
        for(int dir = 0; dir < 4; dir++){
            int nx = cur.x + dx[dir];
            int ny = cur.y + dy[dir];
            if(nx < 0 || nx > 500 || ny < 0 || ny > 500)continue;
            if(danger[nx][ny] == 2 || board[nx][ny] == 0)continue;
            if(board[nx][ny] != -1 && board[nx][ny] <= cur.cost + danger[nx][ny])continue;
            board[nx][ny] = cur.cost + danger[nx][ny];
            q.push({nx, ny, cur.cost + danger[nx][ny]});
        }
    }
    cout << board[500][500] << '\n';
}