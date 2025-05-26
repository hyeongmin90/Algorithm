#include <bits/stdc++.h>

using namespace std;

double arr[3];

double func(int x1, int y1, int x2, int y2){
    int x = abs(x1 - x2);
    int y = abs(y1 - y2);
    double dist = sqrt(x * x + y * y);
    return dist;
}

int main(){
    double ax, ay, bx, by, cx, cy;
    cin >> ax >> ay >> bx >> by >> cx >> cy;
    
    if(((bx - ax) * (cy - ay) - (by - ay) * (cx - ax)) == 0){
        cout << -1 << '\n';
        return 0;
    }

    arr[0] = func(ax, ay, bx, by);
    arr[1] = func(bx, by, cx, cy);
    arr[2] = func(cx, cy, ax, ay);
    sort(arr, arr + 3);
    cout << fixed;
    cout.precision(15);
    cout << ((arr[1] + arr[2]) - (arr[0] + arr[1])) * 2 << '\n';
}