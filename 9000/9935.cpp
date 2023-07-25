#include<iostream>
using namespace std;

void solution() {
	string s, bomb, answer="";
	cin >> s >> bomb;
	int len = bomb.length();
	for (int i = 0; i < s.length(); ++i) {
		answer += s[i];
		int aLen = answer.length();
		if (aLen < len) continue;
		if (!bomb.compare(answer.substr(aLen - len, aLen))) {
			answer.erase(aLen - len, aLen);
		}
	}
	if (answer.empty()) {
		cout << "FRULA";
		return;
	}
	cout << answer;
}

int main() {
	cin.tie(0), cout.tie(0);
	ios_base::sync_with_stdio(0);
	solution();
	return 0;
}
