#include<iostream>
#include<vector>
#include<map>
using namespace std;

int n;
map<string, int> m;
vector<int> seq;

void input() {
	cin >> n;
	string s;
	for (int i = 0; i < n; ++i) {
		cin >> s;
		m[s] = i;
	}
	for (int i = 0; i < n; ++i) {
		cin >> s;
		seq.push_back(m[s]);
	}
}

void solution() {
	input();
	int answer = 0;
	for (int i = 0; i < n; ++i) {
		for (int j = i + 1; j < n; ++j) {
			if (seq[i] > seq[j]) {
				++answer;
				break;
			}
		}
	}
	cout << answer;
}

int main() {
	cin.tie(0), cout.tie(0);
	ios_base::sync_with_stdio(0);
	solution();
	return 0;
}
