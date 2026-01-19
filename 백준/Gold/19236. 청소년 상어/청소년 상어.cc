#include <bits/stdc++.h>

using namespace std;

int dx[8] = {-1, -1, 0, 1, 1, 1, 0, -1};
int dy[8] = {0, -1, -1, -1, 0, 1, 1, 1};
int ans;

struct fish {
    pair<int, int> arr[4][4];
    pair<int, int> locate[17];
};

fish fish_move(int cur_x, int cur_y, fish map, int shark_dir){
    fish new_map = map;
    for(int i = 1; i <= 16; i++){
        
        auto l = new_map.locate[i];
        if (l.first == -1 && l.second == -1) continue;

        int fish_dir = new_map.arr[l.first][l.second].second;
        int nx, ny;
        bool can_move = false;
        for(int k = 0; k < 8; k++){
            nx = l.first + dx[fish_dir];
            ny = l.second + dy[fish_dir];
            if((nx == cur_x && ny == cur_y) || (nx < 0 || nx >= 4 || ny < 0 || ny >= 4)){
                fish_dir = (fish_dir + 1) % 8;
                continue;
            }
            can_move = true;
            break;
        }
        if(!can_move) continue;
        auto t = new_map.arr[nx][ny];
        new_map.arr[l.first][l.second] = t;
        new_map.arr[nx][ny] = {i, fish_dir};
        if (t.first != -1) new_map.locate[t.first] = {l.first, l.second};
        new_map.locate[i] = {nx, ny};

    }
    return new_map;
}

void simulation(int cur_x, int cur_y, int shark_dir, int cnt, fish map){
    auto target = map.arr[cur_x][cur_y];
    int fish_num = target.first, fish_dir = target.second;
    if (fish_num != -1){
        cnt += fish_num;
        shark_dir = map.arr[cur_x][cur_y].second;

        map.arr[cur_x][cur_y] = {-1, -1};
        map.locate[fish_num] = {-1, -1};
    }

    fish nxt = fish_move(cur_x, cur_y, map, shark_dir);

    bool can_move = false;
    for(int i = 1; i <= 3; i++){
        int nx = cur_x + dx[shark_dir] * i;
        int ny = cur_y + dy[shark_dir] * i;
        if(nx < 0 || nx >= 4 || ny < 0 || ny >= 4) break;
        if(nxt.arr[nx][ny].first == -1) continue;
        simulation(nx, ny, shark_dir, cnt, nxt);
        can_move = true;
    }

    if(!can_move) ans = max(ans, cnt);
}

int main(){
    fish map;
    for(int i = 0; i < 4; i++){
        for(int j = 0; j < 4; j++){
            int a, b;
            cin >> a >> b;
            map.arr[i][j] = {a, b - 1};
            map.locate[a] = {i, j};
        }
    }
    
    simulation(0, 0, 0, 0, map);
    cout << ans << '\n';
}