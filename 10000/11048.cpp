#include <iostream>
using namespace std;
#define MAX 1001

int n, m;
int area[MAX][MAX];
int dp[MAX][MAX];
int dx[]{ 0,1,1 };
int dy[]{ 1,0,1 };

void init() {
	cin >> n >> m;
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= m; ++j) {
			cin >> area[i][j];
		}
	}
}

void solution() {
	init();
	int answer = 0;
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= m; ++j) {
			dp[i][j] = max(dp[i][j - 1], dp[i - 1][j]) + area[i][j];
			if (answer < dp[i][j]) answer = dp[i][j];
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
