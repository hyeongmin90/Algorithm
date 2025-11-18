#include <bits/stdc++.h>

using namespace std;

map<char, int> number_1 = {
    {'M', 1000},
    {'D', 500},
    {'C', 100},
    {'L', 50},
    {'X', 10},
    {'V', 5},
    {'I', 1}
};

map<int, string> number_2 = {
    {1000, "M"},
    {500, "D"},
    {100, "C"},
    {50, "L"},
    {10, "X"},
    {5, "V"},
    {1, "I"}
};



int to_arabic(string roman){
    int ans = 0;
    int pre = 0;
    for (int i = 0; i < roman.size(); i++){
        char l = roman[i];
        int cur = number_1[l];

        if(pre < cur){
            ans -= 2 * pre;
        }
        pre = cur;
        ans += cur;
    }
    return ans;
}

string to_roman(int arabic){
    vector<string> v;
    int d = 1;
    while(arabic > 0){
        int a = arabic % 10;
        arabic /= 10;
        if(a % 5 == 4){
            int b = a > 5 ? 10 : 5;
            v.push_back(number_2[d] + number_2[d * b]);
        }
        else{
            string tmp = "";
            if (a >= 5){
                tmp += number_2[d * 5];
                a -= 5;
            }
            for (int i = 0; i < a; i++){
                tmp += number_2[d];
            }
            v.push_back(tmp);
        }
        d *= 10;
    }
    reverse(v.begin(), v.end());
    string ans = "";
    for (auto x : v) ans += x;

    return ans;
}

int main(){
    string a, b;
    cin >> a >> b;
    int num = to_arabic(a) + to_arabic(b);
    cout << num << '\n' << to_roman(num) << '\n';
}