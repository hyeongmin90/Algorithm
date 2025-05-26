#include <bits/stdc++.h>

using namespace std;

string password[101];


int main(){
    int n; cin >> n;
    for(int i = 0; i < n; i++)
        cin >> password[i];

    for(int i = 0; i < n; i++){
        string re = password[i];
        reverse(re.begin(), re.end());
        int sz = re.size();
        if(re == password[i]){
            cout << sz << ' ' << re[sz / 2];
            return 0;
        }
        for(int j = 0; j < i; j++){
            if(re == password[j]){
                cout << sz << ' ' << re[sz / 2];
                return 0;
            }
        }
    }
}