#include <iostream>
#include <algorithm>
#include <cmath>
#include <stack>
#define X first
#define Y second

using namespace std;

int n, l;
int board[102][102];
int board2[102][102];
int cnt;
bool check2;//지나갈수 있는지

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    cin >> n >> l;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> board[i][j];
        }
    }
    for (int k = 0; k < 2;k++){
        for (int i = 0; i < n; i++)
        {
            stack<pair<int, int>> s; // 땅의 높이, 높이가 연속된 정도
            bool check = false;      // 경사로 필요 유무
            check2 = false;
            for (int j = 0; j < n; j++)
            {
                // 스택 비어있음
                if (s.empty())
                {
                    s.push({board[i][j], 1});
                    continue;
                }
                // 마지막 값과 같은 값
                if (s.top().X == board[i][j])
                {
                    // 경사로가 필요하고 길이가 충족될시
                    if (check && s.top().Y + 1 >= l)
                    {
                        while (!s.empty())
                            s.pop();
                        s.push({board[i][j], 0});
                        check = false;
                        continue;
                    }
                    s.push({board[i][j], s.top().Y + 1});

                    continue;
                }
                // 1 이상 차이나거나 경사로가 아직 설치안했을 때 높이가 변함
                if (abs(s.top().X - board[i][j]) > 1 || check){
                    check2 = true;
                    break;
                }

                // 마지막 값보다 큰 값
                if (s.top().X < board[i][j])
                {
                    // 경사로 설치 불가
                    if (s.top().Y < l){
                        check2 = true;
                        break;
                    }
                    while (!s.empty())
                        s.pop();
                    s.push({board[i][j], 1});
                    continue;
                }
                // 마지막 값보다 작은 값
                // 경사로 길이가 1일때 처리
                if (l == 1)
                {
                    while (!s.empty())
                        s.pop();
                    s.push({board[i][j], 0});
                    continue;
                }
                s.push({board[i][j], 1});
                check = true;
            }
            //경사로 필요 & 경사로 불가
            if (check || check2)
                continue;
            cnt++;
        }
        //돌리기
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                board2[i][j] = board[i][j];

        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                board[i][j] = board2[n - 1 - j][i];
    }
    cout << cnt;
    return 0;
}