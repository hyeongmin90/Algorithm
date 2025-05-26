#include <iostream>
#include <algorithm>

using namespace std;

int a[100][100];
int b[100][100];
int ab[100][100];

int main()
{
	int N, M, K;
	cin >> N >> M;
	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++)
			cin >> a[i][j];
	
	cin >> M >> K;
	for (int i = 0; i < M; i++)
		for (int j = 0; j < K; j++)
			cin >> b[i][j];

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < K; j++) {
			for (int h = 0; h < M; h++) {
				ab[i][j] += a[i][h] * b[h][j];
			}
		}
	}
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < K; j++) {
			cout << ab[i][j]<<" ";
		}
		cout << '\n';
	}
	return 0;
}