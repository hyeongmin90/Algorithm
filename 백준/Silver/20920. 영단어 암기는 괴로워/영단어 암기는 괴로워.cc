#include <bits/stdc++.h>

using namespace std;

unordered_map<string, int> cnt;

struct compare {
    bool operator()(const string& a, const string& b) const {
        if(cnt[a] != cnt[b]) return cnt[a] > cnt[b];
        if(a.length() != b.length()) return a.length() > b.length();
        return a < b;
    }
};
vector<string> v;

int main(){
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n, m;
    cin >> n >> m;
    for(int i = 0; i < n; i++){
        string word;
        cin >> word;
        if(word.length() < m) continue;
        cnt[word]++;
        v.push_back(word);
    }
    sort(v.begin(), v.end(), compare());
    v.erase(unique(v.begin(), v.end()), v.end());

    for(string word : v){
        cout << word << '\n';
    }
}