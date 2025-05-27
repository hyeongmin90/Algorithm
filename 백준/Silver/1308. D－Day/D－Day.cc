#include <bits/stdc++.h>

using namespace std;

int month[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

bool leap_year(int year){
    if(year % 4 == 0 && (year % 100 != 0 || year % 400 == 0)) return true;
    return false;
}

int day(int y, int m, int d){
    int n = 0;
    for(int i = 0; i < y; i++){
        n += 365 + leap_year(i);
    }
    for(int i = 1; i < m; i++){
        n += month[i];
        if(i == 2) n += leap_year(y);
    }
    n += d;
    return n;
}

int main(){
    int y1, m1, d1, y2, m2, d2;
    cin >> y1 >> m1 >> d1 >> y2 >> m2 >> d2;

    if(y2 - y1 > 1000 || (y2 - y1 == 1000 && (m2 >= m1 && d2 >= d1))){
        cout << "gg" << '\n';
        return 0;
    }

    int n = day(y1, m1, d1);
    int m = day(y2, m2, d2);
    
    cout << "D-" << m - n << '\n';
}