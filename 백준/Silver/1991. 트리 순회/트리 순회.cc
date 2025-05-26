#include <bits/stdc++.h>
#define Left first
#define Right second

using namespace std;

pair<int, int> tree[26];

void func1(int a){
    if(a < 0) return;
    char tmp = a + 'A';
    cout << tmp;
    func1(tree[a].Left);
    func1(tree[a].Right);
}
void func2(int a){
    if(a < 0) return;
    func2(tree[a].Left);
    char tmp = a + 'A';
    cout << tmp;
    func2(tree[a].Right);
}
void func3(int a){
    if(a < 0) return;
    func3(tree[a].Left);
    func3(tree[a].Right);
    char tmp = a + 'A';
    cout << tmp;
}
int main(){
    int n; cin >> n;
    for(int i = 0; i < n; i++){
        char a, l, r;
        cin >> a >> l >> r;
        tree[a - 'A'] = {l - 'A', r - 'A'};
    }
    func1(0);
    cout << '\n';
    func2(0);
    cout << '\n';
    func3(0);
    cout << '\n';
}