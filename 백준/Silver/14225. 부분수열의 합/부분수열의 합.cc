#include <bits/stdc++.h>

using namespace std;

int arr[21];
bool vis[21];
int n;
unordered_set<int> s;

void dfs(int depth, int j, int sum, int k){
    if(depth == k){
        s.insert(sum);
        return;
    }
    for(int i = j; i < n; i++){
        if(vis[i]) continue;
        vis[i] = 1;
        dfs(depth + 1, i + 1, sum + arr[i], k);
        vis[i] = 0;
    }
}

int main(){
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }
    for(int i = 1; i <= n; i++){
        dfs(0, 0, 0, i);
    }

    int a = 1;
    while(1){
        if(s.find(a) == s.end()){
            cout << a << '\n';
            break;
        }
        a++;
    }
}