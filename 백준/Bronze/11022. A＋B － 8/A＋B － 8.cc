#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

using namespace std;

int main(){
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int a, b,n,i;
    
    cin >> n;
    for (i = 1; i <= n; i++)
    {
        cin >> a >> b;
        cout <<"Case #"<<i<<": "<<a<<" + "<<b<<" = " << a + b << '\n';
    }
    
    
    
    return 0;
}