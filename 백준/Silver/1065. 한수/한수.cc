#include <iostream>

using namespace std;
int Q[4];

int d(int a) {
    int k = 0;
    int num;
    int sum[3];
    int cnt = 0;
    int i = 0;
    num = a;
    while (num != 0) {//자릿수 분리
        Q[i] = num % 10;
        num /= 10;
        i++;
    }
    if (a < 100) cnt++;
    else {
        for (int j = 0; j + 1 < i; j++) {
            sum[j] = Q[j] - Q[j + 1];
        }
        if (a >= 1000) {
            if (sum[0] == sum[1] && sum[1] == sum[2])cnt++;
        }
        else {
            if (sum[0] == sum[1])cnt++;
        }
    }
    return cnt;
}
int main() {
    int n;
    int b=0;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        int a = d(i);
        b += a;
    }
    
    cout << b;
    return 0;
 }