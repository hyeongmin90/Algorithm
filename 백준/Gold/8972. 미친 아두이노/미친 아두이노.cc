#include <bits/stdc++.h>

using namespace std;

int r, c;
int board[101][101];
int dx[10] = {0, 1, 1, 1, 0, 0, 0, -1, -1, -1};
int dy[10] = {0, -1, 0, 1, -1, 0, 1, -1, 0, 1};
vector<pair<int, int>> robots;
pair<int, int> cur;


bool robots_move(){
    for(auto &robot : robots){
        int x = robot.first, y = robot.second;
        int dist = INT_MAX, dir = -1;
        for(int i = 1; i <= 9; i++){
            int nx = x + dx[i];
            int ny = y + dy[i];
            if(nx < 0 || nx >= r || ny < 0 || ny >= c) continue;
            int d = abs(cur.first - nx) + abs(cur.second - ny);
            if(dist > d){
                dist = d;
                dir = i;
            }
        }
        board[x][y] = 0;
        int nx = x + dx[dir];
        int ny = y + dy[dir];
        if(nx == cur.first && ny == cur.second) return true;
        robot = {nx, ny};
    }
    map<pair<int, int>, int> m;
    for(auto &robot : robots){
        m[robot]++;
    }
    vector<pair<int, int>> v;
    for(auto [k, val] : m){
        if(val > 1) continue;
        board[k.first][k.second] = 2;
        v.push_back(k);
    }
    robots = v;
    return false;
}

bool simulation(int dir){
    int nx = cur.first + dx[dir];
    int ny = cur.second + dy[dir];
    if(board[nx][ny] == 2) return true;
    board[cur.first][cur.second] = 0;
    cur = {nx, ny};
    board[nx][ny] = 1;
    return robots_move();
}

int main(){
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> r >> c;
    for(int i = 0; i < r; i++){
        string str;
        cin >> str;
        for(int j = 0; j < c; j++){
            if(str[j] == 'I') {
                board[i][j] = 1;
                cur = {i, j};
            }
            else if(str[j] == 'R') {
                board[i][j] = 2;
                robots.push_back({i, j});
            }
        }
    }
    string move;
    cin >> move;
    for(int i = 0; i < move.length(); i++){
        int cur = move[i] - '0';
        if(simulation(cur)){
            cout << "kraj " << i + 1 << '\n';
            return 0;
        }
    }
    for(int i = 0; i < r; i++){
        for(int j = 0; j < c; j++){
            int a = board[i][j];
            if(a == 0) cout << '.';
            else if(a == 1) cout << 'I';
            else cout << 'R';
        }
        cout << '\n';
    }
}