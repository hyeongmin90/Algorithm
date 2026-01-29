#include <bits/stdc++.h>

using namespace std;

vector<vector<pair<int, string>>> rooms;

bool compare(const pair<int, string> &a, const pair<int, string> &b){
    if(a.second == b.second) return a.first < b.first;
    return a.second < b.second;
}

int main(){
    int p, m;
    cin >> p >> m;
    for(int i = 0; i < p; i++){
        int l;
        string name;
        cin >> l >> name;
        bool flag = false;
        for(int i = 0; i < rooms.size(); i++){
            int level = rooms[i][0].first;
            if(rooms[i].size() >= m) continue;
            if(abs(level - l) <= 10){
                rooms[i].push_back({l, name});
                flag = true;
                break;
            }
        }
        if(!flag){
            vector<pair<int, string>> room;
            room.push_back({l, name});
            rooms.push_back(room);
        }
    }
    for(auto room : rooms){
        if(room.size() == m) cout << "Started!" << '\n';
        else cout << "Waiting!" << '\n';

        sort(room.begin(), room.end(), compare);

        for(auto x : room){
            cout << x.first << ' ' << x.second << '\n';
        }
    }
}