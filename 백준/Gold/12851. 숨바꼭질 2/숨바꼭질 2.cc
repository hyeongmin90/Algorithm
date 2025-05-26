#include <bits/stdc++.h>

using namespace std;

int arr[100001];
queue<int> q;

int main(){
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n, m, cnt = 1;
    cin >> n >> m;
    fill(arr, arr + 100001, -1);
    arr[n] = 0;
    q.push(n);
    while(!q.empty()){
        auto cur = q.front();
        q.pop();
        for(auto nxt : {cur + 1, cur - 1, cur * 2}){
            if(nxt < 0 || nxt > 100000) continue;
            if(arr[nxt] != -1 && arr[nxt] != arr[cur] + 1) continue;
            if(arr[nxt] != -1 && nxt == m) cnt++;
            arr[nxt] = arr[cur] + 1;
            q.push(nxt);
        }
    }
    cout << arr[m] << '\n' << cnt << '\n';
}