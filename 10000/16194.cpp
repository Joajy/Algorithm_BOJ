#include <iostream>
using namespace std;

int n;
int p[1001], dp[1001]{ 0 };

int min(int a, int b){
    if(a < b) return a;
    return b;
}

void input() {
	cin >> n;
	for (int i = 1; i <= n; ++i) {
		cin >> p[i];
	}
}

void solution() {
	input();
	for (int i = 1; i <= n; ++i) {
		dp[i] = p[i];
		for (int j = 1; j < i; ++j) {
			dp[i] = min(dp[i], dp[i - j] + dp[j]);
		}
	}
	cout << dp[n];
}

int main() {
	cin.tie(0), cout.tie(0);
	ios_base::sync_with_stdio(0);
	solution();
	return 0;
}
