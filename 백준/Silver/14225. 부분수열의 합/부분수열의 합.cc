#include <bits/stdc++.h>

using namespace std;

int arr[21];
bool check[2000001];
int n;
unordered_set<int> s;

void dfs(int depth, int j, int sum){
    check[sum] = true;
    if(depth == n) return;
    for(int i = j; i < n; i++){
        dfs(depth + 1, i + 1, sum + arr[i]);
    }
}

int main(){
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }
    dfs(0, 0, 0);

    int a = 1;
    while(check[a]) a++;
    cout << a << '\n';
}