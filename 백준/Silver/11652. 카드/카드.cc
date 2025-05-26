#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

vector<long long> v;
int n;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    cin >> n;
    for (int i = 0; i < n; i++){
        long long tmp;
        cin >> tmp;
        v.push_back(tmp);
    }
    sort(v.begin(), v.end());
    long long mx = 0, cnt = 0, val = 0, mxval = 0;
    for (int i = 0; i < v.size(); i++){
        if(v[i] != val){
            if(mx < cnt)
                mxval = val;
            mx = max(mx, cnt);
            cnt = 1;
            val = v[i];
        }
        else
            cnt++;
    }
    if(mx < cnt)
        mxval = val;
    cout << mxval;
    return 0;
}