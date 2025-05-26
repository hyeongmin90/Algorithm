#include <iostream>
#include <algorithm>
#include <vector>
#include <deque>
using namespace std;

int player[52][10];
int board[10] = {1, 2, 3, 4, 5, 6, 7, 8};
int ans, idx, n;

void game(vector<int> board2)
{
    int cnt = 0;
    // 이닝
    for (int inning = 0; inning < n; inning++)
    {
        int out = 0;
        deque<int> d;
        bool base[4] = {};
        while (out != 3)
        {
            base[0] = true;
            if (player[inning][board2[idx]] == 0) out++;
            else
            {
                int move = player[inning][board2[idx]];
                for (int i = 3; i >= 0;i--){
                    if(!base[i])continue;
                    if((i + move) > 3)
                        cnt++;
                    else{
                        base[i + move] = true;
                    }
                    base[i] = false;
                }
            }
            idx = (idx + 1) % 9;
        }
    }
   
    ans = max(ans, cnt);
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    cin >> n;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < 9; j++)
            cin >> player[i][j];

    do // 0번 선수를 제외한 조합 생성
    {
        
        vector<int> v;
        idx = 0;
        // 0번 선수가 4번째 순서인 조합 생성
        for (int i = 0; i < 8; i++)
        {
            if (i == 3)
                v.push_back(0);
            v.push_back(board[i]);
        }

        game(v);

    } while (next_permutation(board, board + 8));

    cout << ans;

    return 0;
}