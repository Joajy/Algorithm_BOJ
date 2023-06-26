#include<iostream>
using namespace std;
#define ll long long

string s;
int num[5001];
ll dp[5001]{ 1,1 };

void input() {
	cin >> s;
	for (int i = 0; i < s.length(); ++i) {
		num[i] = s[i] - '0';
	}
}

void solution() {
	input();
	if (num[0] == 0) {
		cout << 0;
		return;
	}
	dp[0] = dp[1] = 1;
	for (int i = 2; i <= s.length(); ++i) {
		int n = num[i - 2] * 10 + num[i - 1];
		if(num[i - 1] > 0) dp[i] = dp[i - 1];
		if (n <= 26 && n >= 10) {
			dp[i] = (dp[i] + dp[i - 2])% 1000000;
		}
	}
	cout << dp[s.length()];
}

int main() {
	cin.tie(0), cout.tie(0), ios_base::sync_with_stdio(0);
	solution();
	return 0;
}
