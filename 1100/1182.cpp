#include<iostream>
#define fast cin.tie(0), cout.tie(0), ios::sync_with_stdio(0);
using namespace std;

bool vis[21];
int n, s, cnt = 0;
int arr[21];

void solve(int idx, int total) {
	if (idx == n) {
		if (s == total)
			cnt++;
		return;
	}
	solve(idx + 1, total);
	solve(idx + 1, total + arr[idx]);
}

int main() {
	fast;
	cin >> n >> s;
	for (int i = 0;i < n;i++)
		cin >> arr[i];
	solve(0, 0);
	if (s == 0)
		cnt--;
	cout << cnt;
	return 0;
}
