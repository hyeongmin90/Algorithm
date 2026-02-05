#include <bits/stdc++.h>

using namespace std;

struct shark{
    int id, x, y, dir;

    int priority[4][4];
};

struct triple{
    int x, y, id;
};

int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};
int n, m, k;
pair<int, int> board[21][21];
vector<shark> sharks;

int simulation(){
    priority_queue<pair<int, pair<int, int>>> pq;
    for(int t = 1; t <= 1000; t++){
        for(auto& shark : sharks){
            int x = shark.x, y = shark.y, dir = shark.dir;
            bool blank = false;
            int f = -1;
            for(int i = 0; i < 4; i++){
                int nx = x + dx[shark.priority[dir][i]];
                int ny = y + dy[shark.priority[dir][i]];
                if(nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
                if(f == -1 && board[nx][ny].first == shark.id) f = i;
                if(board[nx][ny].first != 0) continue;
                shark.x = nx;
                shark.y = ny;
                shark.dir = shark.priority[dir][i];
                blank = true;
                break;
            }
            if(!blank){
                int nx = x + dx[shark.priority[dir][f]];
                int ny = y + dy[shark.priority[dir][f]];
                shark.x = nx;
                shark.y = ny;
                shark.dir = shark.priority[dir][f];
            }
            pq.push({shark.id * -1, {shark.x, shark.y}});
        }

        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                if(board[i][j].second == 0) continue;
                board[i][j].second--;
                if(board[i][j].second == 0) board[i][j] = {0, 0};
            }
        }

        while(!pq.empty()){
            auto [id, xy] = pq.top();
            auto [x, y] = xy;
            id *= -1;
            pq.pop();
            if(board[x][y].first != id && board[x][y].first != 0){
                sharks.erase(remove_if(sharks.begin(), sharks.end(), 
                    [id](const shark& shark) {
                        return shark.id == id;
                    }), sharks.end());
                continue;
            }
            board[x][y] = {id, k};
        }
        if(sharks.size() == 1) return t;
    }
    return -1;
}

int main(){
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> n >> m >> k;
    sharks.resize(m);
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            int a;
            cin >> a;
            if(a != 0){
                board[i][j] = {a, k};
                sharks[a - 1] = {a, i, j};
            }
        }
    }

    for(int i = 0; i < m; i++){
        int dir;
        cin >> dir;
        sharks[i].dir = dir - 1;
    }
    
    for(int k = 0; k < m; k++){
        for(int i = 0; i < 4; i++){
            for(int j = 0; j < 4; j++){
                int a;
                cin >> a;
                sharks[k].priority[i][j] = a - 1;
            }
        }
    }

    cout << simulation() << '\n';
}