#include<iostream>
#include<queue>
#include<utility>
#include<cmath>
#define fast cin.tie(0), cout.tie(0), ios::sync_with_stdio(0)
using namespace std;
using pi = pair<int, int>;
int main() {
    fast;
	priority_queue<pi> q;
	int n, x;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> x;
		if (x != 0)
			q.push({ -abs(x), -x });
		else {
			if (q.empty()) {
				cout << 0 << '\n';
				continue;
			}
			cout << -q.top().second << '\n';
			q.pop();
		}
	}
	return 0;
}
