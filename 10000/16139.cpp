#include <iostream>
#include <string>
using namespace std;

string s;
int q;
int prefix[26][200001]{ 0 };

void init() {
	cin >> s >> q;
}

void calculate() {
	for (int i = 1; i <= s.length(); ++i) {
		for (int j = 0; j < 26; ++j) {
			if (j == s[i - 1] - 'a') {
				prefix[j][i] = prefix[j][i - 1] + 1;
			}
			else {
				prefix[j][i] = prefix[j][i - 1];
			}
		}
	}
}

void solution() {
    init();
	calculate();
	char a;
	int l, r;
	for (int i = 0; i < q; ++i) {
		cin >> a >> l >> r;
		cout << prefix[a - 'a'][r + 1] - prefix[a - 'a'][l] << '\n';
	}
}

int main() {
	cin.tie(0), cout.tie(0);
	ios_base::sync_with_stdio(0);
	solution();
	return 0;
}
