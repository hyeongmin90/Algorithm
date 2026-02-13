#include <bits/stdc++.h>

using namespace std;

map<string, int> m;
bool pass[1001];

int main(){
    int n;
    cin >> n;
    for(int i = 0; i < n; i++){
        string car;
        cin >> car;
        m[car] = i;
    }
    int order = 0, cnt = 0;
    for(int i = 0; i < n; i++){
        string car;
        cin >> car;
        pass[m[car]] = 1;
        if(m[car] > order) cnt++;
        while(pass[order]){
            order++;
        }
    }
    cout << cnt << '\n';
}