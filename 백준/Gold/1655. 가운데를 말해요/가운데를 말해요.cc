#include <bits/stdc++.h>

using namespace std;

priority_queue<int> maxh;
priority_queue<int, vector<int>, greater<int>> minh;

int main(){
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n; cin >> n;
    for(int i = 0; i < n; i++){
        int num; cin >> num;

        if(!maxh.size()){
            maxh.push(num);
            cout << maxh.top() << '\n';
            continue;
        }
        
        if(num > maxh.top()){
            if(maxh.size() == minh.size()){
                minh.push(num);
                maxh.push(minh.top());
                minh.pop();
            }
            else
                minh.push(num);
        }
        else{ //maxh.top() >= num;
            if(maxh.size() >= minh.size() + 1){
                maxh.push(num);
                minh.push(maxh.top());
                maxh.pop();
            }
            else
                maxh.push(num);
        }
        cout << maxh.top() << '\n';
    }
    
}