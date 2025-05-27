#include <bits/stdc++.h>

using namespace std;

int parent[1000001];

int getParent(int a){
    if(parent[a] == a) return a;
    return parent[a] = getParent(parent[a]);
}

void UnionParent(int a, int b){
    a = getParent(a);
    b = getParent(b);
    if(a < b) parent[b] = a;
    else parent[a] = b;
}
void findParent(int a, int b){
    a = getParent(a);
    b = getParent(b);
    cout << (a == b ? "YES" : "NO") << '\n';
}

int main(){
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n, m;
    cin >> n >> m;
    for(int i = 0; i <= n; i++){
        parent[i] = i;
    }
    for(int i = 0; i < m; i++){
        int a, b, c;
        cin >> a >> b >> c;
        if(a == 1) findParent(b, c);
        else UnionParent(b, c);
    }
}