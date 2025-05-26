#include <iostream>
#include <cmath>
using namespace std;

void hanoi(int n,int from, int by, int to) {
   
    if (n == 1) {
        cout << from << " " << to << '\n';
    }
    else {
        hanoi(n - 1, from, to, by);
        cout << from << " " << to << '\n';
        hanoi(n - 1, by, from, to);
    }
}
int main() {
    int n;
    cin >> n;
    int k = pow(2, n) - 1;
    cout << k << '\n';
    hanoi(n, 1, 2, 3);
   
    return 0;
}