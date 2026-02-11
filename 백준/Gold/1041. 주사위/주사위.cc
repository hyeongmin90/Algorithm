#include <bits/stdc++.h>

using namespace std;

int main(){
    long long n;
    cin >> n;
    long long a, b, c, d, e, f;
    cin >> a >> b >> c >> d >> e >> f;
    long long dice[4] = {e, a, b, f};
    long long top = d;
    long long bottom = c;
    long long min_side = min({a, b, c, d, e, f});

    if(n == 1){
        int sum = a + b + c + d + e + f;
        sum -= max({a, b, c, d, e, f});
        cout << sum << '\n';
        return 0;
    }

    long long three_sides = 1000, two_sides = 1000;

    for(int i = 0; i < 4; i++){
        long long A = dice[i] + dice[(i + 1) % 4];
        three_sides = min({three_sides, A + top, A + bottom});
        two_sides = min({two_sides, A, dice[i] + top, dice[i] + bottom});
    }

    
    long long side = (min_side * (n - 2) * (n - 1) * 4) + (min_side * (n - 2) * (n - 2));
    long long edge = (two_sides * (n - 1) * 4) + (two_sides * (n - 2) * 4);
    long long vertex = three_sides * 4;
    long long ans = side + edge + vertex;
    cout << ans << '\n';
}