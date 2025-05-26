#include <iostream>
#include <algorithm>

using namespace std;

string arr[51];

bool cmp(string &a, string &b)
{
    if (a.size() != b.size())
        return a.size() < b.size();
    int num = 0, num2 = 0;
    for (int i = 0; i < a.size(); i++)
        if (isdigit(a[i]))
            num += (a[i] - '0');
        
    for (int i = 0; i < b.size(); i++)
        if (isdigit(b[i]))
            num2 += (b[i] - '0');
        
    if (num != num2)
        return num < num2;
    return a < b;
}

int main()
{
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    sort(arr, arr + n, cmp);
    for (int i = 0; i < n; i++)
        cout << arr[i] << '\n';

    return 0;
}