#include <bits/stdc++.h>

using namespace std;

vector<int> v;
int tri[10][10];

int main(){
    int n, m;
    cin >> n >> m;
    for(int i = 1; i <= n; i++) v.push_back(i);

    do{
        for(int i = 0; i < n; i++) tri[0][i] = v[i];
        for(int i = 1; i < n; i++){
            for(int j = 0; j + i < n; j++){
                tri[i][j] = tri[i - 1][j] + tri[i - 1][j + 1];
            }
        }
        if(tri[n - 1][0] == m){
            for(auto x : v) cout << x << ' ';
            break;
        }
        
    }while(next_permutation(v.begin(), v.end()));
}