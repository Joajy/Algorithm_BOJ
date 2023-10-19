#include<iostream>
#include<vector>
#define p pair<int, int>
using namespace std;

int n, m;
int dp[10001];
vector<p> v[10001];
void input() {
	cin >> n >> m;
	int st, en, cost;
	for (int i = 0; i < n; ++i) {
		cin >> st >> en >> cost;
		if (en - st <= cost || en > m) continue;
		v[st].push_back({ en, cost });
	}
}

void solve() {
	for (int i = 0; i <= m; ++i) {		dp[i] = i;	}
	for (int i = 0; i <= m; ++i) {
		dp[i + 1] = min(dp[i + 1], dp[i] + 1);
		for (p j : v[i]) {
			if (dp[j.first] > dp[i] + j.second) {
				dp[j.first] = dp[i] + j.second;
			}
		}
	}
	cout << dp[m];
}

int main() {
	cin.tie(0), cout.tie(0);
	ios_base::sync_with_stdio(0);
	input();
	solve();
	return 0;
}
