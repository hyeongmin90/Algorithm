#include <bits/stdc++.h>

using namespace std;

string d[3] = {"qwertyuiop", "asdfghjkl00", "zxcvbnm000"};
pair<int, int> dd[26];

void func(){
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 10; j++){
            if(d[i][j] == '0')continue;
            dd[d[i][j] - 'a'] = {i, j};
        }
    }
}

int main(){
    int t; cin >> t;
    func();
    while(t--){
        string word[11];
        string input;
        vector<pair<int, string>> v;
        int n;
        cin >> input >> n;
        for(int i = 0; i < n; i++)
            cin >> word[i];
        
        for(int i = 0; i < n; i++){
            int dis = 0;
            for(int j = 0; j < input.size(); j++){
                if(word[i][j] == input[j])continue;
                auto [x1, y1] = dd[word[i][j] - 'a'];
                auto [x2, y2] = dd[input[j] - 'a'];
                dis += abs(x1 - x2) + abs(y1 - y2);
            }
            v.push_back(make_pair(dis, word[i]));
        }
        sort(v.begin(), v.end());
        for(auto x : v) cout << x.second << ' ' << x.first << '\n';
    }
}