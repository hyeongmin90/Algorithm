#include <bits/stdc++.h>

using namespace std;

int arr[100001];
int n, m;
int ans = 0x7fffffff;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    cin >> n >> m;
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    sort(arr, arr + n);

    int j = 0;
    for (int i = 0; i < n; i++)
    {
        while (j < n && arr[j] - arr[i] < m)
            j++;
        if(j >= n)break;
        if(arr[j] - arr[i] >= m) ans = min(ans, arr[j] - arr[i]);
    }
    cout << ans << '\n';

    return 0;
}