#include <bits/stdc++.h>

using namespace std;

int height[257];
int n, m, b;
int minVal = 256;
int maxVal = 0;

void func(){
    int i = minVal, j = maxVal;
    int minCnt = height[i], maxCnt = height[j];
    int time = 0;
    while(i < j){
        if (minCnt <= b && minCnt <= maxCnt * 2){
            b -= minCnt;
            time += minCnt;
            minCnt += height[++i];
        }
        else{
            time += maxCnt * 2;
            b += maxCnt;
            maxCnt += height[--j];
        }
    }
    cout << time << ' ' << i << '\n';
}

int main(){
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> n >> m >> b;
    for(int i = 0; i < n * m; i++){
        int a; cin >> a;
        minVal = min(minVal, a);
        maxVal = max(maxVal, a);
        height[a]++;
    }
    func();
}