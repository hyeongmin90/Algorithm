#include <bits/stdc++.h>

using namespace std;

int alphabet[26];
string str; 

bool check(){
    if(str.size() % 2 == 0){
        for(auto x : alphabet) 
            if (x % 2 != 0) return 1;
    }
    else{
        int cnt = 0;
        for(auto x : alphabet) 
            if(x % 2 != 0) cnt++;

        if (cnt > 1) return 1;
    }
    return 0;
}

int main(){
    cin >> str;
    for(int i = 0; i < str.size(); i++)
        alphabet[str[i] - 'A']++;
    
    if(check()){
        cout << "I'm Sorry Hansoo\n";
        return 0;
    }
    string result = "";
    string ans = "";
    string mid = "";
    for(int i = 0; i < 26; i++){
        if(alphabet[i] == 0)continue;
        if(alphabet[i] % 2 != 0) mid = 'A' + i;
        
        for(int j = 0; j < alphabet[i] / 2; j++){
            result += 'A' + i;
        }
    }
    ans += result + mid;
    reverse(result.begin(), result.end());
    ans += result;

    cout << ans << '\n';
}