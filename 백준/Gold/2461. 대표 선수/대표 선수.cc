#include <bits/stdc++.h>

using namespace std;

int n, k;
vector<pair<int, int>> v;
int check[1001];

int main(){
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> n >> k;
    for(int i = 1; i <= n; i++){
        for(int j = 0; j < k; j++){
            int num;
            cin >> num;
            v.push_back({num, i});
        }
    }
    sort(v.begin(), v.end());

    int j = 0, ans = 0x7fffffff, cnt = 0;
    for(int i = 0; i < v.size(); i++){
        while(j < v.size() && cnt < n){
            if(!check[v[j].second]) cnt++;
            check[v[j++].second]++;
        }
        if(cnt == n) ans = min(ans, v[j - 1].first - v[i].first);
        check[v[i].second]--;
        if(!check[v[i].second])cnt--;
    }
    cout << ans << '\n';
}