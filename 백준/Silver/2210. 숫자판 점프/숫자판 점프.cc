#include <bits/stdc++.h>

using namespace std;

int board[5][5];
unordered_set<string> s;
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
int arr[6];

void func(){
    string result = "";
    for(int i = 0; i < 6; i++){
        result += ('0' + arr[i]);
    }
    s.insert(result);
}

void dfs(int depth, int x, int y){
    if(depth == 6){
        func();
        return;
    }
    arr[depth] = board[x][y];
    for(int dir = 0; dir < 4; dir++){
        int nx = x + dx[dir];
        int ny = y + dy[dir];
        if(nx < 0 || nx >= 5 || ny < 0 || ny >= 5) continue;
        dfs(depth + 1, nx, ny);
    }
}

int main(){
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    for(int i = 0; i < 5; i++){
        for(int j = 0; j < 5; j++){
            cin >> board[i][j];
        }
    }

    for(int i = 0; i < 5; i++){
        for(int j = 0; j < 5; j++){
            dfs(0, i, j);
        }
    }
    cout << s.size() << '\n';
}

