#include<iostream>
using namespace std;

int parent[1000001];

int Find(int x) {
	if (parent[x] == x) return x;
	return parent[x] = Find(parent[x]);
}

void Union(int a, int b) {
	a = Find(a);
	b = Find(b);
	if (a != b) parent[b] = a;
}

int main() {
	cin.tie(0), cout.tie(0);
	ios_base::sync_with_stdio(0);	
	int n, m, a, b, c;
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
		parent[i] = i;
	while (m--) {
		cin >> a >> b >> c;
		if (a == 0)
			Union(b, c);
		else {
			b = Find(b);
			c = Find(c);
			if (b == c)
				cout << "YES\n";
			else
				cout << "NO\n";
		}			
	}
	return 0;
}
