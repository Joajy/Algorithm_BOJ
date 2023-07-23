#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int n, c;
int x[1000001];
vector<int> repo, v;

void input() {
	cin >> n ;
	for (int i = 0; i < n; ++i) {
		cin >> x[i];
		repo.push_back(x[i]);
	}
}

void solution() {
	input();
	sort(repo.begin(), repo.end());
	v.push_back(repo[0]);
	for (int i = 1; i < n; ++i) {
		if (repo[i] != repo[i - 1]) v.push_back(repo[i]);
	}
	for (int i = 0; i < n; ++i) {
		cout << lower_bound(v.begin(), v.end(), x[i]) - v.begin() << ' ';
	}
}

int main() {
	cin.tie(0), cout.tie(0);
	ios_base::sync_with_stdio(0);
	solution();
	return 0;
}
