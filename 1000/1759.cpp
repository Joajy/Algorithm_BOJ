#include<iostream>
#include<algorithm>
using namespace std;

int l, c;

char alphabet[15];
char cntAlp[5]{ 'a','e','i','o','u' };
char ans[15];

void dfs(int cnt) {
	if (cnt + 1 == l) {
		int count = 0;
		for (int i = 0; i < l; ++i) {
			for (int j = 0; j < 5; ++j) {
				if (ans[i] == cntAlp[j]) {
					++count;
					break;
				}
			}
		}
		if (count == 0 || cnt + 1 - count < 2) return;
		for (int i = 0; i < l; ++i) {
			cout << ans[i];
		}cout << '\n';
	}
	for (int i = 0; i < c; ++i) {
		if (ans[cnt] >= alphabet[i]) continue;
		ans[cnt + 1] = alphabet[i];
		dfs(cnt + 1);
	}
}

void solution() {
	cin >> l >> c;
	for (int i = 0; i < c; ++i) cin >> alphabet[i];
	sort(alphabet, alphabet + c);
	for (int i = 0; i <= c - l; ++i) {
		ans[0] = alphabet[i];
		dfs(0);
	}
}

int main() {
	cin.tie(0), cout.tie(0), ios_base::sync_with_stdio(0);
	solution();
	return 0;
}
