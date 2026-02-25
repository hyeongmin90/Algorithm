#include <bits/stdc++.h>

using namespace std;

int operators[10];
vector<string> ans;

void func(int n){
    vector<char> v;
    v.push_back('1');
    for(int i = 0; i < n - 1; i++){
        if(operators[i] == 0){
            v.push_back('+');
        }
        else if(operators[i] == 1){
            v.push_back('-');
        }
        else v.push_back(' ');
        v.push_back('0' + (i + 2));
    }
    
    vector<int> num, oper;
    int tmp = 0;
    for(auto a : v){
        if(a == ' ') continue;
        if(isdigit(a)){
            tmp *= 10;
            tmp += a - '0';
        }
        else{
            num.push_back(tmp);
            tmp = 0;
            oper.push_back((a == '+' ? 0 : 1));
        }
    }
    num.push_back(tmp);

    int sum = num[0];
    for(int i = 0; i < oper.size(); i++){
        if(oper[i] == 0) sum += num[i + 1];
        else sum -= num[i + 1];
    }
    if(sum == 0){
        string s(v.begin(), v.end());
        ans.push_back(s);
    }
}

void dfs(int n, int depth){
    if(n - 1 == depth){
        func(n);
        return;
    }
    for(int i = 0; i < 3; i++){
        operators[depth] = i;
        dfs(n, depth + 1);
    }
}

int main(){
    ios::sync_with_stdio(0), cin.tie(0);
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        dfs(n, 0);
        sort(ans.begin(), ans.end());
        for(auto s : ans){
            cout << s << '\n';
        }
        cout << '\n';
        ans.clear();
    }
}