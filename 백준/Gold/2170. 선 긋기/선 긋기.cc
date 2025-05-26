#include <bits/stdc++.h>

using namespace std;

vector<pair<int, int>> v;
int ans;

int main(){
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n; cin >> n;
    for(int i = 0; i < n; i++){
        int x, y;
        cin >> x >> y;
        v.push_back({x, y});
    }
    sort(v.begin(), v.end());

    int start = v[0].first;
    int end = v[0].second;
    
    for(int i = 1; i < n; i++){
        if(v[i].first <= end){
            end = max(end, v[i].second);
        }
        else{
            ans += end - start;
            start = v[i].first;
            end = v[i].second;
        }
    }

    ans += end - start;

    cout << ans << '\n';
}