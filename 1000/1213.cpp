#include<iostream>
using namespace std;

int n, m;
string s;
int cnt = 0;
int alp[26];

void input() {
	cin >> s;
}

void solve() {
	for (char i : s) {
		++alp[i - 'A'];
	}
	for (int i = 0; i < 26; ++i) {
		if (alp[i] % 2 == 1) ++cnt;
		if (cnt > 1) {
			cout << "I'm Sorry Hansoo";
			return;
		}
	}
	string answer = "";
	char temp = 0;
	for (int i = 0; i < 26; ++i) {
		if (alp[i] == 0) continue;
		if (alp[i] % 2 == 1) {
			temp = i + 'A';
			--alp[i];
		}
		for (int j = 0; j < alp[i] / 2; ++j) {
			answer += (i + 'A');
		}
	}
	if (temp != 0) answer += temp;
	for (int i = 25; i >= 0; --i) {
		if (alp[i] == 0) continue;
		for (int j = 0; j < alp[i] / 2; ++j) {
			answer += (i + 'A');
		}
	}
	cout << answer;
}

int main() {
	cin.tie(0), cout.tie(0);
	ios_base::sync_with_stdio(0);
	input();
	solve();
	return 0;
}
