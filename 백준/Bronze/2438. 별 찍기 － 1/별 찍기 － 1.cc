#include <iostream>

using namespace std;

int main(){
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int a, b,n,i,j;
    
    cin >> n;
    for (i = 1; i <= n; i++) {
        for (j = 1; j <= i; j++)
            cout << "*";

        cout << '\n';
    }
    
    
    return 0;
}