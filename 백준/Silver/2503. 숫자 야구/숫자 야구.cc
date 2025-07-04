#include <bits/stdc++.h>

using namespace std;

struct triple
{
    string a;
    int b, c;
};

int n, ans;
triple question[101];
bool vis[10];

bool func2(string num){
    for(int i = 0; i < n; i++){
        auto [q, s, b] = question[i];
        int ns = 0, nb = 0;
        for(int j = 0; j < 3; j++){
            for(int k = 0; k < 3; k++){
                if(num[j] == q[k]){
                    if(j == k) ns++;
                    else nb++;
                }
            }
        }
        if(s != ns || b != nb) return false;
    }
    return true;
}

void func(int depth, string num){
    if(depth == 3){
        if (func2(num)) ans++;
        return;
    }
    for(int i = 1; i <= 9; i++){
        if(vis[i]) continue;
        vis[i] = 1;
        func(depth + 1, num + to_string(i));
        vis[i] = 0;
    }
}

int main(){
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> n;
    for(int i = 0; i < n; i++){
        string num;
        int s, b;
        cin >> num >> s >> b;
        question[i] = {num, s, b};
    }
    func(0, "");
    cout << ans << '\n';
}

