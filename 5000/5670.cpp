#include<iostream>
#include<vector>
#include<map>
#include<iomanip>
using namespace std;

struct Trie {
private
:	bool isEnd = false;
	map<char, Trie*> child;
public:
	void insert(string s, int idx) {
		if (s.length() == idx) {
			this->isEnd = true;
			return;
		}
		if (child[s[idx]] == nullptr) {
			child[s[idx]] = new Trie();
		}
		child[s[idx]]->insert(s, idx + 1);
	}
	int countAuto(string s) {
		int cnt = 1;
		Trie* t = child[s[0]];
		for (int i = 1; i < s.length(); ++i) {
			if (t->child.size() > 1 || t->isEnd == true) {
				++cnt;
			}
			t = t->child[s[i]];
		}
		return cnt;
	}
};

double solution(int n) {
	vector<string> v(n);
	for (int i = 0; i < n; ++i) {
		cin >> v[i];
	}
	Trie* root = new Trie();
	for (auto s : v) {
		root->insert(s, 0);
	}
	int sum = 0;
	for (auto s : v) {
		sum += root->countAuto(s);
	}
	double answer = (double)sum / n;
	return answer;
}

int main() {
	cin.tie(0), cout.tie(0);
	ios_base::sync_with_stdio(0);
	int t;
	while (cin >> t) {
		cout << fixed << setprecision(2) << solution(t) << '\n';
	}
	return 0;
}
