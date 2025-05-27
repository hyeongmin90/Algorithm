#include <iostream>
#include <string>
using namespace std;

int main() {
    int n, a;
    cin >> n;
    for (int i = 666; n != 0; i++)
    {
        string b = to_string(i);
        if (b.find("666") != string::npos)
        {
            a = i;
            n--;
        }
        else continue;
    }
    cout << a;
    return 0;
}