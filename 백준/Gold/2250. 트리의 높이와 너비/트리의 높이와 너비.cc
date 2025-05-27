#include <bits/stdc++.h>

using namespace std;

struct Node{
    int par;
    int Left;
    int Right;
};

queue<int> level[10001];
Node tree[10001];
int col = 1;
int Maxlv;
int root;

void findroot(int n){
    if(!tree[n].par){
        root = n;
        return;
    }
    findroot(tree[n].par);
}

void preorder(int node, int lv){
    if(node == -1)return;
    Maxlv = max(Maxlv, lv);
    preorder(tree[node].Left, lv + 1);
    level[lv].push(col++);
    preorder(tree[node].Right, lv + 1);
}

int main(){
    int n; cin >> n;
    for(int i = 0; i < n; i++){
        int a, l, r;
        cin >> a >> l >> r;
        tree[a].Left = l;
        tree[a].Right = r;
        tree[l].par = a;
        tree[r].par = a;
    }
    findroot(1);
    preorder(root, 1);
    int ans = 0, lv = 0;
    for(int i = 1; i <= Maxlv; i++){
        if(ans < level[i].back() - level[i].front() + 1){
            ans = level[i].back() - level[i].front() + 1;
            lv = i;
        }
    }
    
    cout << lv << ' ' << ans << '\n';

}