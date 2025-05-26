#include <bits/stdc++.h>

using namespace std;

vector<int> tree[51];

int ans;
int erase;

void func(int a){
    if(a == erase) return;
    if(tree[a].empty()){
        ans++;
        return;
    }
    for(int i = 0; i < tree[a].size(); i++){
        if(tree[a][i] == erase){
            if(tree[a].size() == 1) ans++;
            continue;
        }
        func(tree[a][i]);
    }
}

int main(){
    int n; cin >> n;
    int root;
    for(int i = 0; i < n; i++){
        int m; cin >> m;
        if(m == -1){
            root = i;
            continue;
        }
        tree[m].push_back(i);
    }
    cin >> erase;
    tree[erase] = vector<int>();
    func(root);
    cout << ans << '\n';
}