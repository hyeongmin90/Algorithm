#include <bits/stdc++.h>

using namespace std;

bool alphabet[27];

int main(){
    ios::sync_with_stdio(0), cin.tie(0);
    int n;
    cin >> n;
    cin.ignore();
    for(int i = 0; i < n; i++){
        string s;
        getline(cin, s);

        bool flag = false;
        for(int j = 0; j < s.length(); j++){ 
            if(s[j] != ' ' && (j == 0 || s[j - 1] == ' ')){
                char lc = tolower(s[j]);
                if(alphabet[lc - 'a']) continue;
                alphabet[lc - 'a'] = 1;
                s.insert(j + 1, "]");
                s.insert(j, "[");
                flag = true;
                break;
            }
        }
        if(!flag){
            for(int j = 0; j < s.length(); j++){
                char c = s[j];
                if(c == ' ') continue;
                char lc = tolower(c);
                if(!alphabet[lc - 'a']){
                    alphabet[lc - 'a'] = 1;
                    s.insert(j + 1, "]");
                    s.insert(j, "[");
                    break;
                }
            }
        }
        
        cout << s << '\n';
    }
}