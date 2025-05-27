#include <iostream>
#include <list>
#include <algorithm>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    string s;
    list<char> note;
    cin >> s;
    for (auto x : s) note.push_back(x);
    auto t = note.end();
    int n;
    cin >> n;
    while (n--) {
        char c;
        cin >> c;
        if (c == 'L') {
            if(t != note.begin()) t--;
        }
        else if (c == 'D') {
            if(t != note.end()) t++;
        }
        else if (c == 'P') {
            char push;
            cin >> push;
            note.insert(t, push);
        }
        else{
            if (t != note.begin()) {
                t--;
                t = note.erase(t);
            }
        }
    }
    for (auto x : note) {
        cout << x;
    }
    return 0;
}
