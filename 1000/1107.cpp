#include<iostream>
#include<string>
using namespace std;

int n, m;
bool isBroken[10];

void input() {
	cin >> n >> m;
	int num;
	for (int i = 0; i < m; ++i) {
		cin >> num;
		isBroken[num] = true;
	}
}

bool isPossible(int num) {
	string s = to_string(num);
	for (int i = 0; i < (int)s.length(); ++i) {
		if (isBroken[s[i] - '0'])
			return false;
	}
	return true;
}

void solution() {
	input();
	string s = to_string(n);
	int answer = abs(n - 100);
	int len;
	for (int i = 0; i < 1000000; ++i) {
		if (isPossible(i)) {
			len = to_string(i).length();
			answer = min(answer, abs(i - n) + len);
		}
	}
	cout << answer;
}

int main() {
	cin.tie(0), cout.tie(0), ios_base::sync_with_stdio(0);
	solution();
	return 0;
}
