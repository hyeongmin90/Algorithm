#include <iostream>
int a = 0;
int b = 1;
int c;
using namespace std;
int A(int n) {
    if (n == 1) return b;
    c = a + b;
    a = b;
    b = c;
    return A(n - 1);
}

int main() {
    
    int num;
    cin >> num;
    if (num == 0) {
        cout << 0;
        return 0;
    }
    cout << A(num);
    
    return 0;
}