#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

using namespace std;

int main(){
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int a[100] = {};
    int i,n,b;
    int sum=0;
    cin >> n;

    for (i = 0; i < n; i++) {
        cin >> a[i];
    }
    cin >> b;
    for (i = 0; i < n; i++) {
        if (a[i] == b) sum++;
    }
    cout << sum << endl;


    return 0;
}