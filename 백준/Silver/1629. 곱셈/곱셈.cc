#include <bits/stdc++.h>

using namespace std;

int a, b, c;
int func(int a, int b){
    if(b == 1)return a;
    long long num = func(a, b/2);
    num = (num * num) % c;
    if(b % 2 != 0) num = (num * a) % c;
    return num;
}

int main(){
    cin >> a >> b >> c;
    cout << func(a, b) % c << '\n';
}