#include <bits/stdc++.h>

using namespace std;

char board[11][11];
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

int main(){
    int r, c;
    cin >> r >> c;
    for(int i = 0; i < r; i++){
        cin >> board[i];
    }

    vector<pair<int, int>> sink;

    for(int i = 0; i < r; i++){
        for(int j = 0; j < c; j++){
            if(board[i][j] == '.') continue;
            int cnt = 0;
            for(int dir = 0; dir < 4; dir++){
                int nx = i + dx[dir];
                int ny = j + dy[dir];
                if(nx < 0 || nx >= r || ny < 0 || ny >= c || board[nx][ny] == '.') cnt++;
            }
            if(cnt >= 3) sink.push_back({i, j});
        }
    }
    for(auto x : sink){
        board[x.first][x.second] = '.';
    }

    int min_x = 11, min_y = 11, max_x = 0, max_y = 0;

    for(int i = 0; i < r; i++){
        for(int j = 0; j < c; j++){
            if(board[i][j] == '.') continue;
            min_x = min(min_x, i);
            min_y = min(min_y, j);
            max_x = max(max_x, i);
            max_y = max(max_y, j);
        }
    }

    for(int i = min_x; i <= max_x; i++){
        for(int j = min_y; j <= max_y; j++){
            cout << board[i][j];
        }
        cout << '\n';
    }
}