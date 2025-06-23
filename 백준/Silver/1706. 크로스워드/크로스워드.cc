#include <bits/stdc++.h>

using namespace std;

string board[21];
vector<string> v;

int main(){
    int n, m;
    cin >> n >> m;
    for(int i = 0; i < n; i++){
        cin >> board[i];
    }

    for(int i = 0; i < n; i++){
        string word = "";
        for(int j = 0; j < m; j++){
            if(board[i][j] == '#'){
                if(word.size() > 1) v.push_back(word);
                word = "";
            }
            else word += board[i][j];
        }
        if(word.size() > 1) v.push_back(word);
    }

    for(int j = 0; j < m; j++){
        string word = "";
        for(int i = 0; i < n; i++){
            if(board[i][j] == '#'){
                if(word.size() > 1) v.push_back(word);
                word = "";
            }
            else word += board[i][j];
        }
        if(word.size() > 1) v.push_back(word);
    }

    sort(v.begin(), v.end());
    cout << v[0] << '\n';
}