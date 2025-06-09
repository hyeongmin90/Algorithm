#include <bits/stdc++.h>

using namespace std;

int arr[100001];
int min_sum = 0x7fffffff, low, high;

int main(){
    int n;
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }
    sort(arr, arr + n);
    int i = 0, j = n - 1;
    while(i < j){
        int sum = arr[i] + arr[j];
        if(abs(min_sum) > abs(sum)){
            min_sum = sum;
            low = arr[i];
            high = arr[j];
        }
        if(sum > 0)j--;
        else i++;
    }
    cout << low << ' ' << high << '\n';
}