#include <iostream>

using namespace std;

long long price[100000];

long long dis[100000];

int main() {

    int n;

    long long sum = 0;

    cin >> n;

    for(int i = 0; i < n-1; i++){ 

        cin >> dis[i];

    }

    for(int i = 0; i < n; i++){

        cin >> price[i];

    }

    long long m = price[0];

    for(int i = 0; i < n-1; i++){ 

        m = min(m, price[i]);

        sum += m * dis[i];

    }

    cout << sum;

    return 0;

}

