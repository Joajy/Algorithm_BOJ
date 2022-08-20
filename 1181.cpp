#include<iostream>
#include<algorithm>
#define fast cin.tie(0), cout.tie(0), ios::sync_with_stdio(0);
using namespace std;

string ans[20001];

bool cmp(string a, string b) {
	if (a.length() == b.length())
		return a < b;
	else
		return a.length() < b.length();
}

int main() {
	fast;
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> ans[i];
		for (int j = 0; j < i; j++) {
			if (ans[i] == ans[j]) {
				i--; n--;
				break;
			}
		}
	}
	sort(ans, ans + n, cmp);
	for (int i = 0; i < n; i++)
		cout << ans[i] << '\n';
	return 0;
}
