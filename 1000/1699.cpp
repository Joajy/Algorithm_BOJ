#include <iostream>
#include <string>
#include <stack>
using namespace std;
#define MAX 100001

int n;
int dp[MAX]{ 0,1 };

int min(int a, int b){
	if (a < b) return a;
	return b;
}

void init() {
	cin >> n;
	for (int i = 1; i <= n; ++i) {
		dp[i] = i;
	}
}

void solution() {
	init();
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j * j <= i; ++j) {
			dp[i] = min(dp[i], dp[i - j * j] + 1);
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
