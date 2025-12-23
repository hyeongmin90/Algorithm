#include <bits/stdc++.h>

using namespace std;

vector<int> v;
vector<pair<int, int>> animals;
int m, n, l;

int binary_find(int x){
    int num = v[0];
    
    int left = 0, right = m - 1;

    while(left <= right){
        int mid = (left + right) / 2;
        int val = v[mid];
        if (val == x) return val;

        if (abs(val - x) < abs(num - x)) num = val;
        
        if (val < x) left = mid + 1;
        else right = mid - 1;
        
    }
    
    return num;
}

int main(){
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> m >> n >> l;
    for(int i = 0; i < m; i++){
        int a;
        cin >> a;
        v.push_back(a);
    }
    for(int i = 0; i < n; i++){
        int x, y;
        cin >> x >> y;
        animals.push_back({x, y});
    }

    sort(v.begin(), v.end());

    int ans = 0;

    for(auto a : animals){
        int x = a.first;
        int y = a.second;
        int num = binary_find(x);

        int dist = abs(x - num) + y;
        if(dist <= l) ans++;
    }

    cout << ans << '\n';
}