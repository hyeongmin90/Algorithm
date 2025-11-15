#include <bits/stdc++.h>

using namespace std;

int edges[101][101];
vector<vector<int>> v;
bool vis[101];

int main(){
    int n;
    cin >> n;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cin >> edges[i][j];
        }
    }

    for(int i = 0; i < n; i++){
        for(int j = 0; j < i; j++){
            if(edges[i][j] != edges[j][i]){
                cout << 0 << '\n';
                return 0;
            }
        }
    }

    for(int i = 0; i < n; i++){
        vector<int> group;
        if(vis[i]) continue;
        group.push_back(i + 1);
        vis[i] = 1;

        for(int j = 0; j < n; j++){
            if (i == j || vis[j]) continue;
            if (edges[i][j] == 0) {
                vis[j] = 1;
                group.push_back(j + 1);
            }
        }
        if (group.size() == 1){
            cout << 0 << '\n';
            return 0;
        }
        v.push_back(group);
    }

    cout << v.size() << '\n';
    for(auto group : v){
        for(auto x : group){
            cout << x << ' ';
        }
        cout << '\n';
    }
}