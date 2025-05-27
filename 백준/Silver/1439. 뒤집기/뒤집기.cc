#include <bits/stdc++.h>

using namespace std;

int main(){
    string num;
    cin >> num;
    int a = 0, b = 0;
    (num[0] == '0' ? a++ : b++);

    for(int i = 1; i < num.size(); i++)
        if(num[i] != num[i - 1]) (num[i] == '0' ? a++ : b++);
        
    cout << min(a, b) << '\n';
}