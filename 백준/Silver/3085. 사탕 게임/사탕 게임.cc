#include <bits/stdc++.h>

using namespace std;

char arr[51][51];
int n, ans;

void swap_candy(int x1, int y1, int x2, int y2){
    char dest[51][51];
    memcpy(dest, arr, sizeof(arr));

    char tmp = dest[x1][y1];
    dest[x1][y1] = dest[x2][y2];
    dest[x2][y2] = tmp;

    int row = 1, col = 1;
    int a = 1;
    
    for(int i = 1; i < n; i++){
        if(x1 == x2){
            if(dest[i][y2] == dest[i - 1][y2]) a++;
            else a = 1;
        }
        else{
            if(dest[x2][i] == dest[x2][i - 1]) a++;
            else a = 1;
        }

        if(dest[x1][i] == dest[x1][i - 1]) row++;
        else row = 1;

        if(dest[i][y1] == dest[i - 1][y1]) col++;
        else col = 1;

        ans = max({ans, row, col, a});
    }
}

int main(){
    cin >> n;
    for(int i = 0; i < n; i++){
        string str;
        cin >> str;
        for(int j = 0; j < n; j++){
            arr[i][j] = str[j];
        }
    }

    for(int i = 0; i < n; i++){
        for(int j = 0; j < n - 1; j++){
            swap_candy(i, j, i, j + 1);
            swap_candy(j, i, j + 1, i);
        }
    }
    cout << ans << '\n';
}