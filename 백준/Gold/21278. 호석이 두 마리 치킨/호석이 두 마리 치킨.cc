#include <bits/stdc++.h>

using namespace std;

int INF = 0x3f3f3f3f;
int dist[101][101];

int main(){
    int n, m;
    cin >> n >> m;

    for(int i = 1; i <= n; i++){
        fill(dist[i], dist[i] + n + 1, INF);
    }

    for(int i = 1; i <= n; i++){
        dist[i][i] = 0;
    }

    for(int i = 0; i < m; i++){
        int u, v;
        cin >> u >> v;
        dist[u][v] = 1;
        dist[v][u] = 1;
    }

    for(int k = 1; k <= n; k++){
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= n; j++){
                dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
            }
        }
    }

    int sum = 0x7fffffff;
    int a = 0, b = 0;
    for(int i = 1; i <= n; i++){
        for(int j = i + 1; j <= n; j++){
            int tmp = 0;
            for(int k = 1; k <= n; k++){
                tmp += min(dist[i][k], dist[j][k]);
            }
            if(sum > tmp){
                a = i;
                b = j;
                sum = tmp;
            }
        }
    }
    cout << a << ' ' << b << ' ' << sum * 2 << '\n';
}