#include <bits/stdc++.h>

using namespace std;

struct qq
{
    int m1;
    int d1;
    int m2;
    int d2;
};

qq f[100001];
pair<int, int> fall = {3, 1};
pair<int, int> tmp;

bool cmp(qq a, qq b){
    if(a.m1 != b.m1) return a.m1 < b.m1;
    else if(a.d1 != b.d1) return a.d1 < b.d1;
    else if(a.m2 != b.m2) return a.m2 < b.m2;
    else return a.d2 < b.d2;
}

bool func(int m, int d){
    if(m < fall.first) return true;
    else if(m == fall.first && d <= fall.second) return true;
     
    return false;
}

int main(){
    int n; cin >> n;
    for(int i = 0; i < n; i++)
        cin >> f[i].m1 >> f[i].d1 >> f[i].m2 >> f[i].d2;
    
    sort(f, f + n, cmp);
    if(f[0].m1 >= 3 && f[0].d1 > 1){
        cout << 0 << '\n';
        return 0;
    }

    int cnt = 0;
    for(int i = 0; i < n; i++){
        if(func(f[i].m1, f[i].d1)){
            if(tmp.first < f[i].m2) 
                tmp = {f[i].m2, f[i].d2};
            else if(tmp.first == f[i].m2 && tmp.second < f[i].d2) 
                tmp = {f[i].m2, f[i].d2};
        }
        if(i + 1 == n){
            if(tmp.first < 12){
                cout << 0 << '\n';
                return 0;
            }
            cnt++;
            break;
        }
        if(!func(f[i + 1].m1, f[i + 1].d1)){
            fall = tmp;
            cnt++;
            if(fall.first > 11)break;
        }
    }
    cout << cnt << '\n';
}