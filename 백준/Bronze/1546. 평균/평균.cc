#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

using namespace std;

int main(){
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
  
    int i,n,max=0;
    double a[1000] = {};
    double sum = 0;
    
    
    cin >> n;
    for (i = 0; i < n; i++) {
        cin >> a[i];
        if (a[i] > max) max = a[i];
    }
    for (i = 0; i < n; i++) {
        a[i] = a[i] / max * 100;
        
        sum += a[i];
    }
    cout << fixed;
    cout.precision(6);
    cout << sum / n << endl;

    return 0;
}