#include<iostream>
#include<vector>
#include<map>
using namespace std;

struct Trie {
private:
	map<string, Trie*> m;
public:
	void insert(vector<string> v, int idx) {
		if (v.size() == idx) return;
		if (m.find(v[idx]) == m.end()) {
			m.insert({ v[idx], new Trie()});
			m[v[idx]]->insert(v, idx + 1);
		}
		else {
			m[v[idx]]->insert(v, idx + 1);
		}
	}

	void find(int depth) {
		for (auto data : m) {
			for (int i = 0; i < depth; i++)
				cout << "--";
			cout << data.first << '\n';
			data.second->find(depth + 1);
		}
	}
};

Trie* root = new Trie();

int main() {
	cin.tie(0);
	ios::sync_with_stdio(0);
	int n, count;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> count;
		vector<string> v(count);
		for (int j = 0; j < count; j++)
			cin >> v[j];
		root->insert(v, 0);
	}
	root->find(0);
	return 0;
}
