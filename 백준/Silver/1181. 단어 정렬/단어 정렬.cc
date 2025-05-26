#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;
bool cmp(string b, string c) {
    if (b.size() == c.size()) return b < c;
    return b.size() < c.size();
}
int main() {
    ios::sync_with_stdio(false); 
    cin.tie(NULL); cout.tie(NULL);
    vector<string>V;
    string a;
    int T;
    cin >> T;
    for (int i = 0; i < T; i++) {
        cin >> a;
        V.push_back(a);
    }
    sort(V.begin(), V.end(),cmp);
    V.erase(unique(V.begin(), V.end()),V.end());
    for (int i = 0; i < V.size(); i++) {
        cout << V[i] <<'\n';
    }
    return 0;
}