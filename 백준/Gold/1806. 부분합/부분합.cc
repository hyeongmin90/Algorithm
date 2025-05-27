#include <bits/stdc++.h>
#define MAXV 0x7fffffff

using namespace std;

int arr[100001];
int n, m;


int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    cin >> n >> m;
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    int j = 0, sum = 0, ans = MAXV;
    for (int i = 0; i < n; i++)
    {
        while (j < n && sum < m)
        {
            sum += arr[j++];
        }
        if(sum >= m) ans = min(ans, j - i); 
        sum -= arr[i];
    }
    cout << (ans == MAXV ? 0 : ans);

    return 0;
}