#include <iostream>

using namespace std;
int main() {
    int cnt=0,sum=0,big,b=0;
    int min, max,j,i;
    cin >> min;
    cin >> max;
    big = max;
    for (j = min; j <= max; j++) {
        cnt = 0;
        for (i = 2; i*i <= j; i++) {
            if (j % i == 0) cnt++;
        }
        if (j != 1 && cnt == 0) {
            sum += j; 
            if (j < big)big = j;
            
        }
    }
    
    if (sum == 0)cout << -1 << endl;
    else cout << sum << '\n'<<big;
    return 0;
 }