#include <bits/stdc++.h>

using namespace std;

map<string, int> m;
int worktime[4] = {4, 6, 4, 10};
string worker;

int main(){
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n; cin >> n;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < 4; j++){
            for(int k = 0; k < 7; k++){
                cin >> worker;
                if(worker == "-")continue;
                m[worker] += worktime[j];
            }
        }
    }
    int MinT = 0x7fffffff;
    int MaxT = 0;
    for(auto lter : m){
        if(lter.second > MaxT) MaxT = lter.second;
        if(lter.second < MinT) MinT = lter.second;
    }
    if(MaxT - MinT > 12) cout << "No" << '\n';
    else cout << "Yes" << '\n';
}
