#include<iostream>
#include<stack>
using namespace std;
#define MAX 1'000'000

int n;
int num[MAX], answer[MAX];

void input() {
	cin >> n;
	for (int i = 0; i < n; ++i) {
		cin >> num[i];
	}
}

void solution() {
	input();
	stack<int> s;
	for (int i = 0; i < n; ++i) {
		while (!s.empty()) {
			if (num[s.top()] < num[i]) {
				answer[s.top()] = num[i];
				s.pop();
			}
			else break;
		}
		s.push(i);
	}
	for (int i = 0; i < n; ++i) {
		if (answer[i] == 0) cout << -1 << ' ';
		else cout << answer[i] << ' ';
	}
}

int main() {
	cin.tie(0), cout.tie(0), ios_base::sync_with_stdio(0);
	solution();
	return 0;
}
