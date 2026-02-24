#include <bits/stdc++.h>

using namespace std;

int board[21][21];
unordered_set<int> edge[401];
int n;
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

int sum(){
    int ans = 0;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            int cnt = 0;
            int a = board[i][j];
            for(int dir = 0; dir < 4; dir++){
                int nx = i + dx[dir];
                int ny = j + dy[dir];
                if(nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
                if(edge[a].find(board[nx][ny]) != edge[a].end()) cnt++;
            }
            if(cnt == 0) continue;
            ans += pow(10, cnt - 1);
        }
    }
    return ans;
}

void func(int a){    
    int adj = -1, blank = -1, x = 0, y = 0;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(board[i][j] != 0) continue;
            int adj_cnt = 0, blank_cnt = 0;
            for(int dir = 0; dir < 4; dir++){
                int nx = i + dx[dir];
                int ny = j + dy[dir];
                if(nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
                if(board[nx][ny] == 0) blank_cnt++;
                else if(edge[a].find(board[nx][ny]) != edge[a].end()) adj_cnt++;
            }
            if(adj < adj_cnt || (adj == adj_cnt && blank < blank_cnt)){
                adj = adj_cnt;
                blank = blank_cnt;
                x = i;
                y = j;
            }
        }
    }
    board[x][y] = a;
}

int main(){
    ios::sync_with_stdio(0), cin.tie(0);
    cin >> n;
    for(int i = 0; i < n * n; i++){
        int a; 
        cin >> a;
        for(int j = 0; j < 4; j++){
            int b;
            cin >> b;
            edge[a].insert(b); 
        }
        func(a);
    }
    cout << sum() << '\n';
    
}