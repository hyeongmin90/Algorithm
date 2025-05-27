#include <bits/stdc++.h>

using namespace std;

stack<int> s;
map<char, int> m;

int main(){
    string str, ans = "";
    cin >> str;
    
    m['*'] = 2;
    m['/'] = 2;
    m['+'] = 1;
    m['-'] = 1;

    int n = str.size();
    for(int i = 0; i < n; i++){
        if(isalpha(str[i])){
            ans += str[i];
        }
        else if(str[i] == '('){
            s.push(str[i]);
        }
        else if(str[i] == ')'){
            while(s.top() != '('){
                ans += s.top();
                s.pop();
            }
            s.pop();
        }
        else{
            while(!s.empty() && s.top() != '(' && m[s.top()] >= m[str[i]]){
                ans += s.top();
                s.pop();
            }
            s.push(str[i]);
        }
    }
    while(!s.empty()){
        ans += s.top();
        s.pop();
    }
    cout << ans << '\n';

}