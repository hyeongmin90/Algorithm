#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
int n, m;

vector<int>v;
bool visit[10001];
int arr[20];

void dfs(int depth) {
	if (depth == m) {
		for (int i = 0; i < m; i++) {
			cout << arr[i] << " ";
		}
		cout << '\n';
		return;
	}
	for (int i = 0; i < v.size(); i++) {
		if (visit[v[i]])continue;
		visit[v[i]] = true;
		arr[depth] = v[i];
		dfs(depth + 1);
		visit[v[i]] = false;
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		int tmp;
		cin >> tmp;
		v.push_back(tmp);
	}
	sort(v.begin(), v.end());
	dfs(0);
	
	return 0;
}