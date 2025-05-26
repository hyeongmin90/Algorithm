#include <bits/stdc++.h>

using namespace std;

int belt[201];
deque<int> robot;
bool isRobot[201];
int input = 0, output;
int Mod, cnt;

void beltMove(int n){
    //벨트 회전
    input = (input - 1 < 0 ? Mod - 1 : input - 1);
    output = (input + n - 1) % Mod;
    if(!robot.empty() && robot.front() == output){
        isRobot[robot.front()] = 0;
        robot.pop_front();
    }
}
void robotMove(){
    //로봇 이동
    bool flag = false;
    for(int i = 0; i < robot.size(); i++){
        int cur = robot[i];
        int nxt = (cur + 1) % Mod;
        if(isRobot[nxt] || belt[nxt] == 0) continue;
        isRobot[cur] = 0;
        belt[nxt]--;
        if(belt[nxt] == 0)cnt++;
        if(nxt == output){
            isRobot[robot.front()] = 0;
            flag = true;
            continue;
        }
        isRobot[nxt] = 1;
        robot[i] = (robot[i] + 1) % Mod;
    }
    if(flag) robot.pop_front();
}

void loadingRobot(){
    //로봇 올리기
    if(belt[input]){
        isRobot[input] = 1;
        belt[input]--;
        if(belt[input] == 0)cnt++;
        robot.push_back(input);
    }
}

int main(){
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n, k;
    cin >> n >> k;
    for(int i = 0; i < n * 2; i++)
        cin >> belt[i];
    
    int level = 0;
    Mod = n * 2;
    while(cnt < k){
        level++;
        beltMove(n);
        robotMove();
        loadingRobot();
    }
    cout << level << '\n';
}