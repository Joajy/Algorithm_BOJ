#include<iostream>
#include<vector>
using namespace std;

int n, m, answer = 0;
vector<int> v[2000];

void input() {
	cin >> n >> m;
	int a, b;
	for (int i = 0; i < m; ++i) {
		cin >> a >> b;
		v[a].push_back(b);
		v[b].push_back(a);
	}
}

void isPossible(int x, int count, bool vis[2000]) {
	if (count == 4) {
		answer = 1;
		return;
	}
	for (int i : v[x]) {
		if (vis[i]) continue;
		vis[i] = 1;
		isPossible(i, count + 1, vis);
		vis[i] = 0;
	}
}

void solution() {
	input();
	for (int i = 0; i < n; ++i) {
		if (v[i].empty()) continue;
		bool vis[2000]{ 0 };
		vis[i] = 1;
		isPossible(i, 0, vis);
		if (answer == 1) break;
	}
	cout << answer;
}

int main() {
	cin.tie(0), cout.tie(0), ios_base::sync_with_stdio(0);
	solution();
	return 0;
}
