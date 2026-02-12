#include <bits/stdc++.h>

using namespace std;

bool func1(string str, int i, int j){
    while(i < j){
        if(str[i] == str[j]){
            i++;
            j--;
            continue;
        }
        return false;
    }
    return true;
}

int func(string str){
    int i = 0, j = str.size() - 1;
    int cnt = 0;
    while(i < j){
        if(str[i] == str[j]){
            i++;
            j--;
            continue;
        }
        if (func1(str, i + 1, j) || func1(str, i, j - 1)) return 1;
        else return 2;
    }
    return 0;
}

int main(){
    ios::sync_with_stdio(0), cin.tie(0);
    int t;
    cin >> t;
    for(int i = 0; i < t; i++){
        string str;
        cin >> str;
        cout << func(str) << '\n';
    }
}