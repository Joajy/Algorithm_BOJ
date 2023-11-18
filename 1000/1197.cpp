#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
using namespace std;
#define p pair<int, int>

vector<p> edge[10001];
bool vis[10001];
int v, e;

void input() {
	cin >> v >> e;
	int a, b, c;
	for (int i = 0; i < e; ++i) {
		cin >> a >> b >> c;
		edge[a].push_back(p(c,b));
		edge[b].push_back(p(c,a));
	}
}

void solution() {
	input();
	int answer = 0;
	priority_queue<p, vector<p>, greater<p>> pq;
	pq.push(p(0, 1));
	while (!pq.empty()) {
		p cur = pq.top(); pq.pop();
		if (vis[cur.second]) continue;
		vis[cur.second] = 1;
		answer += cur.first;
		for (p i : edge[cur.second]) {
			if (!vis[i.second]) {
				pq.push(i);
			}
		}
	}
	cout<< answer;
}

int main() {
	cin.tie(0), cout.tie(0);
	ios_base::sync_with_stdio(0);
	solution();
	return 0;
}
