#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n, m, x, y;
vector<int> p, q;

void init() {
	cin >> n >> m;
	int dx, dy;
	for (int i = 0; i < m; ++i) {
		cin >> dx >> dy;
		p.push_back(dx);
		q.push_back(dy);
	}
	sort(p.begin(), p.end());
	sort(q.begin(), q.end());
	x = p[m >> 1];
	y = q[m >> 1];
}

int abs(int a) {
	if (a < 0) return -a;
	return a;
}

void solution() {
	init();
	int answer = 0;
	for (int i = 0; i < m; ++i) {
		answer += abs(p[i] - x) + abs(q[i] - y);
	}
	cout << answer;
}

int main() {
	cin.tie(0), cout.tie(0);
	ios_base::sync_with_stdio(0);
	solution();
	return 0;
}
