#include <iostream>

using namespace std;

int main() {//a=97 z=122
    char abc[21]={};
    int ABC[26] = {};

    int N, n;
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> n >> abc;
        int j = 0;
        while (abc[j] != 0) {
            for (int l = 0; l < n; l++) {
                cout << abc[j];
            }
            j++;
        }
        cout << endl;


  }
    
    return 0;
 }