#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
#define MAX 100
#define p pair<int, int>
vector<p> line{ {0,0} };
int n, dp[MAX + 1];

void input() {
	cin >> n;
	int a, b;
	for (register int i = 0; i < n; ++i) {
		cin >> a >> b;
		line.emplace_back(a, b);
	}
}

void solution() {
	input();
	sort(line.begin(), line.end());
	int answer = MAX;
	dp[1] = 1;
	for (register int i = 1; i <= n; ++i) {
		for (register int j = i; j >= 0; --j) {
			if (line[i].second <= line[j].second) continue;
			if (dp[i] > dp[j]) continue;
			dp[i] = dp[j] + 1;
		}
	}
	for (int i = 1; i <= n; ++i) {
		answer = min(answer, n - dp[i]);
	}
	cout << answer;
}

int main() {
	cin.tie(0), cout.tie(0), ios_base::sync_with_stdio(0);
	solution();
	return 0;
}
