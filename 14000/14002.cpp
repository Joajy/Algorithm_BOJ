#include<iostream>
#include<vector>
using namespace std;

int a[1000001];
vector<int> v[1000001];

int main() {
	cin.tie(0); cout.tie(0);
	ios_base::sync_with_stdio(0);
	int n, Max = 0;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		v[i].push_back(a[i]);
	}
	for (int i = 0; i < n; i++) {
		for (int j = i + 1; j < n; j++) {
			if (a[i] < a[j]) {
				if (v[i].size() + 1 > v[j].size()) {
					v[j] = v[i];
					v[j].push_back(a[j]);
				}
				else {
					if(v[i].size() > v[j].size())
						v[j] = v[i];
				}
			}
		}
		if (v[Max].size() < v[i].size())
			Max = i;
	}
	cout << v[Max].size() << '\n';
	for (auto i : v[Max])
		cout << i << ' ';
	return 0;
}
