#include <bits/stdc++.h>

using namespace std;

int S;
int L;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int n;
    string skill;
    cin >> n >> skill;
    int ans = 0;
    for (int i = 0; i < n; i++){
        if(skill[i] >= '1' && skill[i] <= '9'){
            ans++;
        }
        else if(skill[i] == 'R')
            if(L > 0){
                ans++;
                L--;
            }
            else
                break;
        else if(skill[i] == 'K'){
            if(S > 0){
                ans++;
                S--;
            }
            else
                break;
        }
        else{
            if(skill[i] == 'L')
                L++;
            else
                S++;
        }
    }
    cout << ans << '\n';
}