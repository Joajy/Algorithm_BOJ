#include<iostream>
#include<algorithm>
#include<string>
using namespace std;

int n, tCnt = 1;

struct Trie {
	bool isEnd;
	Trie* child[26];
	int cnt;
	Trie() {
		isEnd = false;
		cnt = 0;
		for (int i = 0; i < 26; ++i) {
			child[i] = nullptr;
		}
	}
	string insert(string s, int idx);
} trie[100001 << 2];

string Trie::insert(string s, int idx){
	if (idx == s.length()) {
		if (++cnt != 1) return s + to_string(cnt);
		return s;
	}
	if (child[s[idx] - 'a'] == nullptr) {
		child[s[idx] - 'a'] = &trie[++tCnt];
		child[s[idx] - 'a']->insert(s, idx + 1);
		return s.substr(0, idx + 1);
	}
	return child[s[idx] - 'a']->insert(s, idx + 1);
}

void input() {
	cin >> n;
}

void solution() {
	input();
	Trie* root = &trie[0];
	string s;
	for (int i = 0; i < n; ++i) {
		cin >> s;
		cout << root->insert(s, 0) << '\n';
	}
}

int main() {
	cin.tie(0), cout.tie(0);
	ios_base::sync_with_stdio(0);
	solution();
	return 0;
}
