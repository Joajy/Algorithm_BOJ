#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;
#define MAX 50
#define p pair<int, int>
int n, m;
int a[MAX][MAX];
int answer = INT_MAX;
vector<p> home, chicken;
bool vis[MAX >> 1];

int getDist(p a, p b) {
	return abs(a.first - b.first) + abs(a.second - b.second);
}

void input() {
	cin >> n >> m;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			cin >> a[i][j];
			if (a[i][j] == 1) home.push_back(make_pair(i, j));
			else if (a[i][j] == 2) chicken.push_back(make_pair(i, j));
		}
	}
}

void minDist() {
	int totalDist = 0;
	for (int i = 0; i < home.size(); ++i) {
		int chickenDist = INT_MAX;
		for (int j = 0; j < chicken.size(); ++j) {
			if (!vis[j]) continue;
			int dist = getDist(home[i], chicken[j]);
			if (dist < chickenDist) {
				chickenDist = dist;
			}
		}
		totalDist += chickenDist;
	}
	if (totalDist < answer) {
		answer = totalDist;
	}
}

void dfs(int idx, int count) {
	if (count == m) {
		minDist();
		return;
	}
	for (int i = idx; i < chicken.size(); ++i) {
		if (vis[i] == 1) continue;
		vis[i] = 1;
		dfs(i + 1, count + 1);
		vis[i] = 0;
	}
}

void solution() {
	input();
	dfs(0, 0);
	cout << answer;
}

int main() {
	cin.tie(0), cout.tie(0), ios_base::sync_with_stdio(0);
	solution();
	return 0;
}
