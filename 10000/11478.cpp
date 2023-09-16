#include <iostream>
#include <set>
using namespace std;

string s;
set<string> se;

void input() {
	cin >> s;
}

void solution() {
	input();
	for (int i = 0; i < s.length(); ++i) {
		for (int j = 1; j <= s.length() - i; ++j) {
			se.insert(s.substr(i, j));
		}
	}
	cout << se.size();
}

int main() {
	cin.tie(0), cout.tie(0);
	ios_base::sync_with_stdio(0);
	solution();
	return 0;
}
