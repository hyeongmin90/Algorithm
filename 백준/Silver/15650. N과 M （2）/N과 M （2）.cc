#include <iostream>

using namespace std;

int n, m;
bool visited[9];
int arr[9];
void dfs(int a, int b) {
	if (a == m) {
		for (int i = 0; i < m; i++) {
			cout << arr[i] << " ";
		}
		cout << '\n';
		return;
	}

	for (int i = b; i <= n; i++) {
		if(!visited[i]) {
			visited[i] = true;
			arr[a] = i;
			dfs(a + 1, i + 1);
			visited[i] = false;
		}
	}
}
int main()
{
	cin >> n >> m;
	dfs(0,1);
	return 0;
}