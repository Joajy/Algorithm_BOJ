#include<iostream>
#include<algorithm>
#include<stack>
#include<vector>
using namespace std;
int n;
int x[101];

void input() {
	cin >> n;
	for (int i = 1; i <= n; ++i) {
		cin >> x[i];
	}
}

void solution() {
	input();
	vector<int> answer;
	for (int i = 1; i <= n; ++i) {
		if (x[i] == i) {
			answer.push_back(i);
			continue;
		}
		bool vis[101]{ 0 };
		vector<int> tmp;
		stack<int> s;
		s.push(x[i]);
		tmp.push_back(x[i]);
		while (!s.empty()) {
			int cur = s.top(); s.pop();
			if (i == cur) {
				answer.insert(answer.begin(), tmp.begin(), tmp.end());
				break;
			}
			if (vis[cur]) break;
			vis[cur] = 1;
			tmp.push_back(x[cur]);
			s.push(x[cur]);
		}
	}
	sort(answer.begin(), answer.end());
	answer.erase(unique(answer.begin(), answer.end()), answer.end());
	cout << answer.size() << '\n';
	for (auto i : answer) {
		cout << i << '\n';
	}
}

int main() {
	cin.tie(0), cout.tie(0);
	ios_base::sync_with_stdio(0);
	solution();
	return 0;
}
