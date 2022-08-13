#include<iostream>
#include<utility>
#include<vector>
#include<algorithm>
#define fast cin.tie(0), cout.tie(0), ios::sync_with_stdio(0);
#define f first
#define s second
using namespace std;

bool cmp(pair<int, string> a, pair<int, string> b) {
	return a.first < b.first;
}

int main() {
	vector<pair<int, string>> v;
	int n, a;
	string b;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a >> b;
		v.push_back({ a,b });
	}
	stable_sort(v.begin(), v.end(), cmp);
	for (int i = 0; i < n; i++) cout << v[i].f << ' ' << v[i].s << '\n';
	return 0;
}
