#include<iostream>
#include<vector>
#include<queue>
using namespace std;
#define p pair<int, int>
int n, m;
p answer = { 100, 987654321 };
vector<int> v[101];

void input() {
	cin >> n >> m;
	int a, b;
	for (int i = 0; i < m; ++i) {
		cin >> a >> b;
		v[a].push_back(b);
		v[b].push_back(a);
	}
}

void solution() {
	input();
	for (int i = 1; i <= n; ++i) {
		bool isFriend[101]{ 0 };
		int sum = 0;
		queue<p> q;
		q.push({ i, 0 });
		isFriend[i] = 1;
		while (!q.empty()) {
			p cur = q.front(); q.pop();
			for (auto x : v[cur.first]) {
				if (isFriend[x]) continue;
				sum += cur.second + 1;
				q.push({ x,cur.second + 1 });
				isFriend[x] = 1;
			}
		}
		if (answer.second > sum) {
			answer.first = i;
			answer.second = sum;
		}
		else if (answer.second == sum && answer.first > i) {
			answer.first = i;
		}
	}
	cout << answer.first;
}

int main() {
	cin.tie(0), cout.tie(0);
	ios_base::sync_with_stdio(0);
	solution();
	return 0;
}
