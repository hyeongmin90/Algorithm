#include <bits/stdc++.h>

using namespace std;

int nation[101];
tuple<int,int,int> info[101];

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int n;
    cin >> n;
    for (int i = 0; i < n; i++){
        int na, num, sco;
        cin >> na >> num >> sco;
        info[i] = {sco, na, num};
    }
    sort(info, info + n, greater<>());
    int award = 0;
    for (int i = 0; i < n && award < 3; i++){
        int a, b, c;
        tie(a, b, c) = info[i];
        if(nation[b] >= 2)continue;
        nation[b]++;
        cout << b << " " << c << '\n';
        award++;
    }
}