#include <bits/stdc++.h>

using namespace std;

int arr[1000001];
vector<int> v;

int main(){
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n; cin >> n;
    for(int i = 0; i < n; i++){
        int a; cin >> a;
        if(v.empty() || v.back() < a) v.push_back(a);
        else{
            int left = 0, right = v.size() - 1;
            while(left < right){
                int mid = (left + right) / 2;
                if(v[mid] < a) left = mid + 1;
                else right = mid;
            }
            v[left] = a;
        }
    }
    cout << v.size() << '\n';
    
}