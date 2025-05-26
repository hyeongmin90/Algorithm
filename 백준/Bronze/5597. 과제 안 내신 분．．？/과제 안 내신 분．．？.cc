#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

using namespace std;

int main(){
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
  
    int i,j;
    int a[30] = {};
    int b[30] = {};

    int max=0;
    

    for (i = 0; i < 30; i++) {
        a[i] = i+1;    
    }

    for (i = 0; i < 28; i++) {
        cin>>b[i];
    }
    for (i = 0; i < 30; i++) {
        for (j = 0; j < 30; j++) {
            if (a[i] == b[j]) a[i] = 0;
        }
    }
    for (i = 0; i < 30; i++) {
        if (a[i] > 0) cout << a[i] << endl;
   }


    return 0;
}