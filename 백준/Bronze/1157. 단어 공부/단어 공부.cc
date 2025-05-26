#include <iostream>

using namespace std;

int main() {
    char abc[1000001]={};
    int ABC[26] = {};
    int max1 = 0;
    int max2 = 0;
    char cnt;
    cin >> abc;
    int j = 0;
 
    while(abc[j]!=0) {
        if (abc[j] > 96)abc[j] -= 32;
        ABC[abc[j] -65] += 1;
        j++;
    }
    for (int i = 0; i < 26; i++) {
        if (ABC[i] > max1) { max1 = ABC[i]; cnt = i+65; }
        else if (ABC[i] == max1) max2 = ABC[i];
    }
    if (max1 > max2) cout << cnt;
    else if (max1 == max2) cout << "?";
    return 0;
 }