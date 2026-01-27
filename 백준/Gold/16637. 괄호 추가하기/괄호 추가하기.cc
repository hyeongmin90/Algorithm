#include <bits/stdc++.h>

using namespace std;

int n, ans = INT_MIN;
bool is_parentheses[11];
vector<int> num;
vector<char> oper;

int calculation(int a, int b, char oper){
    if(oper == '*') return a * b;
    else if(oper == '+') return a + b;
    else return a - b;
}

void func(){
    vector<int> numbers;
    vector<char> operators;
    for(int i = 0; i < num.size(); i++){
        if(numbers.empty()){
            numbers.push_back(num[i]);
            continue;
        }
        if(is_parentheses[i - 1]){
            int a = calculation(num[i - 1], num[i], oper[i - 1]);
            numbers.back() = a;
            continue;
        }
        numbers.push_back(num[i]);
        operators.push_back(oper[i - 1]);
    }

    int cnt = numbers[0];
    for(int i = 1; i < numbers.size(); i++){
        cnt = calculation(cnt, numbers[i], operators[i - 1]);
    }
    ans = max(ans, cnt);
}

void func1(int i){
    func();
    for(i; i < n / 2; i++){
        if(is_parentheses[i]) continue;
        if(i > 0 && is_parentheses[i - 1]) continue;
        is_parentheses[i] = true;
        func1(i + 1);
        is_parentheses[i] = false;
    }
}

int main(){
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    string expression;
    cin >> n >> expression;
    for(int i = 0; i < n; i++){
        char cur = expression[i];
        if (isdigit(cur)) num.push_back(cur - '0');
        else oper.push_back(cur);
    }
    func1(0);
    cout << ans << '\n';
}