#include<iostream>
#include<queue>
#include<vector>
using namespace std;

struct p {
	int x;
	vector<int> v;
};

int n, k;
bool vis[100001];

void solution() {
	cin >> n >> k;
	if (n == k) {
		cout << 0 << '\n' << n;
		return;
	}
	if (n > k) {
		cout << n - k << '\n';
		for (int i = n; i >= k; --i) {
			cout << i << ' ';
		}
		return;
	}
	queue<p> q;
	q.push({ n, {n} });
	vis[n] = 1;
	while (!q.empty()) {
		p cur = q.front(); q.pop();
		if (cur.x == k) {
			cout << cur.v.size() - 1 << '\n';
			for (auto i : cur.v) {
				cout << i << ' ';
			}
			return;
		}
		int move[3] = { cur.x - 1, cur.x + 1, cur.x << 1 };
		for (int i = 0; i < 3; ++i) {
			if (move[i] > 100000 || move[i] < 0) continue;
			if (vis[move[i]]) continue;
			vis[move[i]] = 1;
			vector<int> tmp = cur.v;
			tmp.push_back(move[i]);
			q.push({ move[i], tmp });
		}
	}
}

int main() {
	cin.tie(0), cout.tie(0);
	ios_base::sync_with_stdio(0);
	solution();
	return 0;
}
