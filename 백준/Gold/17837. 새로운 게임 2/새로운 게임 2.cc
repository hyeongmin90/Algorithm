#include <bits/stdc++.h>

using namespace std;

struct piece
{
    int x, y, dir;
};

int color[13][13];
vector<int> board[13][13];
vector<piece> pieces;
int dx[4] = {0, 0, -1, 1};
int dy[4] = {1, -1, 0, 0};
int n, k;

bool simulation(){
    for(int i = 0; i < k; i++){
        auto cur = pieces[i];
        int x = cur.x;
        int y = cur.y;
        int dir = cur.dir;

        int nx = x + dx[dir];
        int ny = y + dy[dir];

        if(nx < 1 || nx > n || ny < 1 || ny > n || color[nx][ny] == 2){
            if(dir == 1) dir = 0;
            else if(dir == 3) dir = 2;
            else dir++;
            pieces[i].dir = dir;
            nx = cur.x + dx[dir];
            ny = cur.y + dy[dir];
        }
        if(nx < 1 || nx > n || ny < 1 || ny > n || color[nx][ny] == 2) continue;

        vector<int>& cur_v = board[x][y];
        auto it = find(cur_v.begin(), cur_v.end(), i);
        vector<int> moving_pieces(it, cur_v.end());
        cur_v.erase(it, cur_v.end());

        if (color[nx][ny] == 1) reverse(moving_pieces.begin(), moving_pieces.end());
        board[nx][ny].insert(board[nx][ny].end(), moving_pieces.begin(), moving_pieces.end());
        if(board[nx][ny].size() >= 4) return true;
        
        for (int i : moving_pieces) {
            pieces[i].x = nx;
            pieces[i].y = ny;
        }
    }
    return false;
}

int main(){
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> n >> k;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            cin >> color[i][j];
        }
    }
    
    for(int i = 0; i < k; i++){
        int x, y, d;
        cin >> x >> y >> d;
        pieces.push_back({x, y, d - 1});
        board[x][y].push_back(i);
    }

    for(int i = 1; i <= 1000; i++){
        if(!simulation()) continue;
        cout << i << '\n';
        return 0;
    }
    cout << -1 << '\n';
}