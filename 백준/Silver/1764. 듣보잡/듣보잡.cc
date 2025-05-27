#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    int n, m;
    vector<string>V;
    string name;
    map<string, int>M1;
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        cin >> name;
        M1[name] = 1;
    }
    for (int i = 0; i < m; i++) {
        cin >> name;
        if (M1.find(name) != M1.end()) {
            V.push_back(name);
        }
    }
    cout << V.size() << '\n';
    sort(V.begin(), V.end());
    for (int i = 0; i < V.size(); i++) {
        cout << V[i] << '\n';
    }
    return 0;
}