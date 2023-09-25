#include<iostream>
using namespace std;

int dp[1000001]{ 0 };
int n, k;

int min(int& a, int& b) {
	if (a < b) return a;
	return b;
}

void input() {
	cin >> n >> k;
}

void solution() {
	input();
	for (int i = 0; i < n; ++i) {
		if (dp[i + 1] == 0) dp[i + 1] = dp[i] + 1;
		else if (dp[i + 1] > dp[i] + 1) dp[i + 1] = dp[i] + 1;
		int jump = i + (i >> 1);
		if (jump <= n) {
			if (dp[jump] == 0) dp[jump] = dp[i] + 1;
			else if(dp[jump] > dp[i] + 1) dp[jump] = dp[i] + 1;
		}
	}
	if (dp[n] <= k) cout << "minigimbob";
	else cout << "water";
}

int main() {
	cin.tie(0), cout.tie(0);
	ios_base::sync_with_stdio(0);
	solution();
	return 0;
}
