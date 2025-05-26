#include <bits/stdc++.h>

using namespace std;

priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
int arr[5000001];

int main(){
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n, k;
    cin >> n >> k;
    for(int i = 0; i < n; i++){
        cin >> arr[i];
        pq.push({arr[i], i});
        while(i - pq.top().second >= k)
            pq.pop();
        cout << pq.top().first << ' ';
    }
}