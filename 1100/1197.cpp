#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
#define MAX 10001
#define X first
#define Y second

int parent[MAX];

int Find(int x) {
	if (parent[x] == x) return x;
	return parent[x] = Find(parent[x]);
}

bool Union(int a, int b) {
	a = Find(a);
	b = Find(b);
	if (a == b) return true;
	parent[b] = a;
	return false;
}

int main() {
	cin.tie(0), cout.tie(0);
	ios_base::sync_with_stdio(0);
	int t, n, m, x, y;
	vector<pair<int, pair<int, int>>> v;
	cin >> n >> m;
	int answer = 0;
	for (int i = 0; i < m; i++) {
		int src, dst, cost;
		cin >> src >> dst >> cost;
		v.push_back({ cost,{src,dst} });
	}
	sort(v.begin(), v.end());
	for (int i = 1; i <= n; i++) parent[i] = i;
	for (int i = 0; i < v.size(); i++)
		if (!Union(v[i].Y.X, v[i].Y.Y)) answer += v[i].X;
	cout << answer;
	return 0;
}
