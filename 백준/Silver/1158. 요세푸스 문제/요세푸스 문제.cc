#include <bits/stdc++.h>

using namespace std;

queue<int> q;
vector<int> ans;

int main(){
    int n, k;
    cin >> n >> k;

    for(int i = 1; i <= n; i++) q.push(i);

    while(!q.empty()){
        for(int i = 0; i < k - 1; i++){
            int a = q.front();
            q.pop(); q.push(a);
        }
        ans.push_back(q.front());
        q.pop();
    }

    cout << "<";
    for(int i = 0; i < ans.size() - 1; i++) cout << ans[i] << ", ";
    cout << ans[ans.size() - 1] << ">" << '\n';
}