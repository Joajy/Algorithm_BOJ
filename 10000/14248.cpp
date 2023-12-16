#include <iostream>
#include <queue>
using namespace std;
#define MAX 100001

int n, s;
int a[MAX];
int mul[]{ 1,-1 };
bool vis[MAX]{ 0 };

void init() {
	cin >> n;
	for (int i = 1; i <= n; ++i) {
		cin >> a[i];
	}
	cin >> s;
}

void solution() {
	init();
	int answer = 0;
	queue<int> q;
	q.push(s);
	vis[s] = 1;
	while (!q.empty()) {
		int cur = q.front(); q.pop();
		++answer;
		for (int i = 0; i < 2; ++i) {
			int nxt = cur + a[cur] * mul[i];
			if (nxt < 1 || nxt > n) continue;
			if (vis[nxt]) continue;
			vis[nxt] = 1;
			q.push(nxt);
		}
	}
	cout << answer;
}

int main() {
	cin.tie(0), cout.tie(0);
	ios_base::sync_with_stdio(0);
	solution();
	return 0;
}
