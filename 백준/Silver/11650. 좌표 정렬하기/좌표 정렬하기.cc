#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
    ios::sync_with_stdio(false); 
    cin.tie(NULL); cout.tie(NULL);
    vector<pair<int,int>>V;
    pair<int, int> p;
    int x, y;
    int T;
    cin >> T;
    for (int i = 0; i < T; i++) {
        cin >> x >> y;
        V.push_back(make_pair(x, y));
    }
    sort(V.begin(), V.end());
    for (int i = 0; i < V.size(); i++) {
        cout << V[i].first << " " << V[i].second << '\n';
    }
    return 0;
}