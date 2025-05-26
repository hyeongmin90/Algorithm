#include <bits/stdc++.h>

using namespace std;

int dx[8] = {-1, -1, 0, 1, 1, 1, 0, -1};
int dy[8] = {0, 1, 1, 1, 0, -1, -1, -1};
//12시 부터 시계방향
queue<int> q;
pair<int, int> king, stone;

int func(string dir){
    int m;
    if(dir == "T") m = 0;
    else if(dir == "RT") m = 1;
    else if(dir == "R") m = 2;
    else if(dir == "RB") m = 3;
    else if(dir == "B") m = 4;
    else if(dir == "LB") m = 5;
    else if(dir == "L") m = 6;
    else m = 7; //(dir == "LT")
    return m;
}

void func2(string l, int k){
    int x = 7 - (l[1] - '0' - 1);
    int y = l[0] - 'A';
    if(k == 1) king = {x, y};
    else stone = {x, y};
}

string func3(pair<int, int> n){
    auto [x, y] = n;
    string result = "";
    result += 'A' + y;
    result += '0' + (8 - x);
    return result;
}

int main(){
    string s, k;
    int n;
    cin >> k >> s >> n;
    func2(k, 1);
    func2(s, 2);
    for(int i = 0; i < n; i++){
        string dir;
        cin >> dir;
        q.push(func(dir));
    }

    while(!q.empty()){
        auto dir = q.front();
        auto [x, y] = king;
        auto [sx, sy] = stone;
        q.pop();
        int nx = x + dx[dir];
        int ny = y + dy[dir];
        if(nx < 0 || nx >= 8 || ny < 0 || ny >= 8)continue;
        if(sx == nx && sy == ny){
            int nnx = nx + dx[dir];
            int nny = ny + dy[dir];
            if(nnx < 0 || nnx >= 8 || nny < 0 || nny >= 8)continue;
            stone = {nnx, nny};
        }
        king = {nx, ny};
    }
    cout << func3(king) << '\n' << func3(stone) << '\n';
}