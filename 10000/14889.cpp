#include <iostream>
#include <vector>
using namespace std;

int n, answer = 987654321;
int s[21][21];
bool vis[21]{0};

int abs(int a, int b) {
	if (a >= b) return a - b;
	return b - a;
}

void input() {
	cin >> n;
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= n; ++j) {
			cin >> s[i][j];
		}
	}
}

void rec(int st, int cnt) {
	if (cnt == (n >> 1)) {
		int team1 = 0, team2 = 0;
		for (int i = 1; i <= n; ++i) {
			for (int j = 1; j <= n; ++j) {
				if (i == j) continue;
				if (vis[i] && vis[j]) {
					team1 += s[i][j] + s[j][i];
				}
				else if (!vis[i] && !vis[j]) {
					team2 += s[i][j] + s[j][i];
				}
			}
		}
		answer = min(answer, abs(team1 - team2));
		return;
	}
	for (int i = st; i <= n; ++i) {
		if (vis[i]) continue;
		vis[i] = 1;
		rec(i + 1, cnt + 1);
		vis[i] = 0;
	}
}

void solution() {
	input();
	rec(1, 0);
	cout << (answer >> 1);
}

int main() {
	cin.tie(0), cout.tie(0);
	ios_base::sync_with_stdio(0);
	solution();
	return 0;
}
