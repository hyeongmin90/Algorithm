#include <bits/stdc++.h>

using namespace std;

int adj[51][51];
int score[51];

int main(){
    int n;
    cin >> n;
    for(int i = 1; i <= n; i++){
        fill(adj[i] + 1, adj[i] + n + 1, 100000);
    }
    while(1){
        int a, b;
        cin >> a >> b;
        if(a == -1 && b == -1)break;
        adj[a][b] = 1;
        adj[b][a] = 1;
    }

    for(int u = 1; u <= n; u++){
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= n; j++){
                if(i == j) adj[i][j] = 0;
                else adj[i][j] = min(adj[i][j], adj[i][u] + adj[u][j]);
            }
        }
    }
    
    for(int i = 1; i <= n; i++){
        score[i] = *max_element(adj[i] + 1, adj[i] + 1 + n);
    }

    int min_score = *min_element(score + 1, score + n + 1);
    int cnt = 0;
    vector<int> ans;

    for(int i = 1; i <= n; i++){
        if(score[i] == min_score){
            cnt++;
            ans.push_back(i);
        }
    }

    cout << min_score << ' ' << cnt << '\n';
    for(int x : ans){
        cout << x << ' ';
    }
}