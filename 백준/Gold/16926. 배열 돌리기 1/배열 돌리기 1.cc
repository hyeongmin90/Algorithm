#include <bits/stdc++.h>

using namespace std;

int arr[301][301];
int n, m, r;
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

void rotate_arr(){
    int a = min(n, m) / 2;
    
    for(int i = 0; i < a; i++){
        int dir = 0;
        int x = i, y = i;
        while(1){
            int nx = x + dx[dir];
            int ny = y + dy[dir];
            if(nx < i || nx >= n - i || ny < i || ny >= m - i){
                dir++;
                continue;
            }
            swap(arr[i][i], arr[nx][ny]);
            x = nx;
            y = ny;
            if(nx == i && ny == i) break;
        }
    }
}

int main(){
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> n >> m >> r;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin >> arr[i][j];
        }
    }
    while(r--)
        rotate_arr();
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cout << arr[i][j] << ' ';
        }
        cout << '\n';
    }
}

