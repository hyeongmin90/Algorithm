#include <iostream>
#include <algorithm>
#include <deque>
#include <sstream>
using namespace std;
bool check = true;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int t;
	cin >> t;
	while (t--) {
		string func, number;
		deque<int>dq;
		int n;
		cin >> func >> n >> number;
		stringstream ss(number.substr(1, number.size() - 2));
		string num;
		while (getline(ss, num, ',')) {
			dq.push_back(stoi(num));;
		}
		int re = 0;
		for (int i = 0; i < func.size(); i++) {
			check = true;
			if (func[i] == 'R') re++;
			if (func[i] == 'D') {
				if (dq.empty()) {
					cout << "error\n";
					check = false;
					break;
				}
				if (re % 2 == 1) {
					dq.pop_back();
				}
				else dq.pop_front();
			}
		}
		if (check) {
			if (re % 2 == 1) {
				cout << "[";
				if (!dq.empty()) {
					for (int i = dq.size() - 1; i > 0; i--) {
						cout << dq[i] << ",";
					}
					cout << dq.front();
				}
				cout << "]\n";
			}
			else {
				cout << "[";
				if (!dq.empty()) {
					for (int i = 0; i < dq.size() - 1; i++) {
						cout << dq[i] << ",";
					}
					cout << dq.back();
				}
				cout << "]\n";
			}
		}
	}
	return 0;
}