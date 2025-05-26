#include <bits/stdc++.h>

using namespace std;

char c[16];
int n, m;
bool vis[16];
char ans[16];
int vow, con;

void func(char c){
    if(c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u') vow++;
    else con++;
}

void func(int depth){
    if(depth == n){
        vow = con = 0;
        for(int i = 0; i < n; i++) func(ans[i]);
        if(vow < 1 || con < 2)return;
        for(int i = 0; i < n; i++)
            cout << ans[i];
        cout << '\n';
        return;
    }
    for(int i = 0; i < m; i++){
        if(vis[i])continue;
        if(ans[depth - 1] >= c[i])continue;
        vis[i] = true;
        func(c[i]);
        ans[depth] = c[i];
        func(depth + 1);
        vis[i] = false;
        func(c[i]);
    }
}

int main(){
    cin >> n >> m;
    for(int i = 0; i < m; i++)
        cin >> c[i];
    
    sort(c, c + m);
    func(0);
}