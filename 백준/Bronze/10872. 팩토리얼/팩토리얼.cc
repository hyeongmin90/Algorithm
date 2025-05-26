#include <iostream>

using namespace std;
int A(int n) {
    if (n == 1) {
        return 1;
    }
    else {
        return n * A(n - 1);   
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    int num;
    cin >> num;
    if (num == 0) {
        cout << 1; 
        return 0;
    }
    cout << A(num);

    return 0;
}