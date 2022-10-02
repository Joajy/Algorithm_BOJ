#include<iostream>
#include<algorithm>
#include<utility>
#define fast cin.tie(0), cout.tie(0), ios::sync_with_stdio(0)
using namespace std;

pair<int, int> a[100002];

bool cmp(pair<int, int> p, pair<int, int> q) {
	if (p.second != q.second)
		return p.second < q.second;
	else if(p.second == q.second)
		return p.first < q.first;
}

int main() {
	fast;
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> a[i].first >> a[i].second;
	sort(a, a + n, cmp);
	for (int i = 0; i < n; i++)
		cout << a[i].first << ' ' << a[i].second << '\n';
	return 0;
}
