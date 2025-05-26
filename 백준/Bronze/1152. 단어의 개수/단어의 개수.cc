#include <iostream>

using namespace std;

int main() {
    int cnt=1;
    char abc[1000001];
    cin.getline(abc, 1000001, '\n');
     
    for (int i = 0; abc[i]!='\0'; i++) {
        if (abc[i] != 32 && abc[i + 1] == 32 && abc[i + 2] > 64) cnt++;  
    }
    if (abc[0]<65&&abc[1]<65) cnt = 0;
    cout << cnt << endl;
    return 0;
 }