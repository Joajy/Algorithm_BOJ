#include<iostream>
#include<vector>
using namespace std;
#define MAX 1'000'001

int n;
vector<int> edge[MAX];
int dp[MAX][2];	//early-adaptor, normal
bool vis[MAX];

void solution(int par) {
	vis[par] = true;
	dp[par][0] = 1;
	for (int child : edge[par]) {
		if (vis[child]) continue;
		solution(child);
		dp[par][1] += dp[child][0];
		dp[par][0] += min(dp[child][0], dp[child][1]);
	}
}

int main() {
	cin.tie(0); cout.tie(0);
	ios::sync_with_stdio(0);
	cin >> n;
	int a, b;
	for (int i = 0; i < n - 1; i++) {
		cin >> a >> b;
		edge[a].push_back(b);
		edge[b].push_back(a);
	}
	solution(1);
	cout << min(dp[1][0], dp[1][1]);
	return 0;
}
