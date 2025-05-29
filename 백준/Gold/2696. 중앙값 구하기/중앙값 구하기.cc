#include <bits/stdc++.h>

using namespace std;

int main(){
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t;
    cin >> t;
    while(t--){
        priority_queue<int> max_heap;
        priority_queue<int, vector<int>, greater<int>> min_heap;
        vector<int> ans;
        int n;
        cin >> n;
        for(int i = 0; i < n; i++){
            int a;
            cin >> a;
            if(max_heap.empty()){
                max_heap.push(a);
            }
            else if(max_heap.top() >= a){
                max_heap.push(a);
            }
            else {
                min_heap.push(a);
            }

            if(max_heap.size() < min_heap.size()){
                max_heap.push(min_heap.top());
                min_heap.pop();
            }
            else if(max_heap.size() - min_heap.size() >= 2){
                min_heap.push(max_heap.top());
                max_heap.pop();
            }
            if(i % 2 == 0)
                ans.push_back(max_heap.top());
        }
        cout << ans.size() << '\n';
        for(int i = 1; i <= ans.size(); i++){
            cout << ans[i - 1] << ' ';
            if(i % 10 == 0) cout << '\n';
        }
        cout << '\n';
    }
}