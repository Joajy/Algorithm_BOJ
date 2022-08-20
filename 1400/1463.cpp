#include<iostream>
#include<queue>
#define fast cin.tie(0), cout.tie(0), ios::sync_with_stdio(0)
using namespace std;

int dp[1000001]{ 0 };
int main() {
	fast;
	int n;
	cin >> n;
	queue<int> q;
	q.push(n);
	while (!q.empty()) {
		int cur = q.front(); q.pop();
		if (cur == 1) break;
		//if cur divided perfectly by 3
		if (cur % 3 == 0) {
			if (dp[cur] + 1 <= dp[cur / 3] || dp[cur / 3] == 0) {
				q.push(cur / 3);
				dp[cur / 3] = dp[cur] + 1;
			}
		}
		//if cur divided perfectly by 2
		if (cur % 2 == 0) {
			if (dp[cur] + 1 <= dp[cur / 2] || dp[cur / 2] == 0) {
				q.push(cur / 2);
				dp[cur / 2] = dp[cur] + 1;
			}
		}
		//else case(not divided by 2 or 3
		if (dp[cur] + 1 <= dp[cur - 1] || dp[cur - 1] == 0) {
			q.push(cur - 1);
			dp[cur - 1] = dp[cur] + 1;
		}
	}
	cout << dp[1];
	return 0;
}
