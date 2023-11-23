#include <iostream>
#include <stack>
using namespace std;
#define MAX 1000001

int n;
int cnt[MAX]{ 0 };
int answer[MAX]{ 0 };
int a[MAX];

void init() {
	cin >> n;
	for (int i = 1; i <= n; ++i) {
		cin >> a[i];
		++cnt[a[i]];
	}
}

void solution() {
	init();
	stack<pair<int, int>> s;
	for (int i = 1; i <= n; ++i) {
		if (s.empty()) {
			s.push({a[i], i});
			continue;
		}
		while (!s.empty()) {
			if (cnt[s.top().first] < cnt[a[i]]) {
				answer[s.top().second] = a[i];
				s.pop();
			}
			else {
				break;
			}
		}
		s.push({a[i], i});
	}

	for (int i = 1; i <= n; ++i) {
		if (answer[i] == 0) {
			cout << -1 << ' ';
		}
		else {
			cout << answer[i] << ' ';
		}
	}
}

int main() {
	cin.tie(0), cout.tie(0);
	ios_base::sync_with_stdio(0);
	solution();
	return 0;
}
