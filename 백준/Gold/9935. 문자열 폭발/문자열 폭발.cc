#include <bits/stdc++.h>

using namespace std;

stack<char> s;

int main(){
    string str, bomb;
    cin >> str >> bomb;
    string temp = "";
    for(int i = 0; i < str.size(); i++){
        temp += str[i];
        if(temp.length() >= bomb.length()){
            string sub = temp.substr(temp.length() - bomb.length());
            if(sub == bomb) 
                temp.erase(temp.length() - bomb.length());
        }
    }


    if(temp.empty()) cout << "FRULA" << '\n';
    else cout << temp << '\n';
}