#include <bits/stdc++.h>
#define X first
#define Y second

using namespace std;

string board[9];
vector<pair<int, int>> v;
bool flag;

bool check(int x, int y, int num){
    char n = '0' + num;
    for(int i = 0; i < 9; i++){
        if(board[x][i] == n) return false;
        if(board[i][y] == n) return false;
    }
    for(int i = (x / 3) * 3; i < (x / 3) * 3 + 3; i++)
        for(int j = (y / 3) * 3; j < (y / 3) * 3 + 3; j++)
            if(board[i][j] == n) return false;
    return true;
}

void func(int depth){
    if(depth == v.size()){
        flag = true;
        return;
    }
    int x = v[depth].X;
    int y = v[depth].Y;
    for(int i = 1; i <= 9; i++){
        if(!check(x, y, i)) continue;
        board[x][y] = '0' + i;
        func(depth + 1);
        if(flag) return;
    }
    board[x][y] = '0';
}


int main(){
    ios::sync_with_stdio(0), cout.tie(0), cin.tie(0);
    for(int i = 0; i < 9; i++){
        cin >> board[i];
        for(int j = 0; j < 9; j++){
            if(board[i][j] == '0') v.push_back({i, j});
        }
    }
    
    func(0);
    for(int i = 0; i < 9; i++)
        cout << board[i] << '\n';
    
}