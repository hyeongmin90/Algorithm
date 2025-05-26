#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

using namespace std;

int main(){
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
  
    int i,n,b;
    int a[9] = {};

    int max=0;
    

    for (i = 0; i < 9; i++) {
        cin >> a[i];
        if (a[i] > max) max=a[i];
    }
    for (i = 0; i < 9; i++) {
        if (max == a[i]) b = i+1;
    }
    cout << max << '\n' << b;
   


    return 0;
}