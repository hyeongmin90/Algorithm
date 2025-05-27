#include <bits/stdc++.h>

using namespace std;

int arr[100001];

int main(){
    int n;
    cin >> n;
    for(int i = 1; i <= n; i++)
        cin >> arr[i];


    int i = 1;
    int j = n;
    int num = 0x7fffffff;
    int x, y;
    while(i < j){
        if(num >= abs(arr[i] + arr[j])){
            num = abs(arr[i] + arr[j]);
            x = arr[i];
            y = arr[j];
        }

        if(abs(arr[i] + arr[j - 1]) < abs(arr[i + 1] + arr[j])){
            j--;
        }
        else{
            i++;
        }

    }

    cout << x << ' ' << y << '\n';
}