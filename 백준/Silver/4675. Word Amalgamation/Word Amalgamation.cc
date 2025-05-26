#include <bits/stdc++.h>

using namespace std;

vector<pair<string, string>> v;

string func(string word){
    int alpa[26] = {};
    for(int i = 0; i < word.size(); i++){
            int m = word[i]  - 'a';
            alpa[m]++;
        }
    string num;
    for(int i = 0; i < 26; i++)
        num += alpa[i] + '0';

    return num;
}

int main(){
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    while (1)
    {
        string word, c;
        cin >> word;
        if(word == "XXXXXX") break;
        c = func(word);
        v.push_back({word, c});
    }
    sort(v.begin(), v.end());
    while(1){
        string word;
        cin >> word;
        if(word == "XXXXXX")break;
        string n = func(word);

        bool check = false;
        for(int i = 0; i < v.size(); i++){
            if(v[i].second == n){
                cout << v[i].first << '\n';
                check = true;
            }
        }
        if(!check) cout << "NOT A VALID WORD\n";
        cout << "******\n";
        check = false;
        
    }
}