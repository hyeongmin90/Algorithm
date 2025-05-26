#include <iostream>
#include <string.h>

using namespace std;
int main() {
    string abc;
    int n;
    int e=0;
    cin >> n;
    for (int i = 0; i < n; i++) {
        int check[26] = {};
        int cnt = 0;
        cin >> abc;
        for (int j = 0; j < abc.length(); j++) {
            check[abc[j]-97] += 1;
            if (abc[j] == abc[j + 1]) check[abc[j]-97] -= 1;
        }
        for (int j = 0; j < 26; j++) {
            if (check[j] > 1) cnt++;
       }
        if (cnt <= 0) e++;
    }
    cout << e << endl;
   
    return 0;
 }