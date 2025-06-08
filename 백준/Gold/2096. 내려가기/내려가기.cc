#include <bits/stdc++.h>

using namespace std;

vector<int> dp_max(3), dp_min(3), new_max(3), new_min(3);

int main(){
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n;
    cin >> n;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < 3; j++){
            int a;
            cin >> a;
            new_max[j] = new_min[j] = a;
        }
        if(i == 0){
            dp_max = new_max;
            dp_min = new_min;
            continue;
        }

        new_max[0] += max(dp_max[0], dp_max[1]);
        new_max[1] += max({dp_max[0], dp_max[1], dp_max[2]});
        new_max[2] += max(dp_max[2], dp_max[1]);

        new_min[0] += min(dp_min[0], dp_min[1]);
        new_min[1] += min({dp_min[0], dp_min[1], dp_min[2]});
        new_min[2] += min(dp_min[2], dp_min[1]);

        dp_max = new_max;
        dp_min = new_min;
    }
    cout << max({dp_max[0], dp_max[1], dp_max[2]}) << ' ' << min({dp_min[0], dp_min[1], dp_min[2]}) << '\n';
}