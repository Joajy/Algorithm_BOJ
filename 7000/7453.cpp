#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

int n;
int a[4001][4];
vector<int> x, y;

void input() {
	cin >> n;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < 4; ++j) {
			cin >> a[i][j];
		}
	}
}

void solution() {
	input();
	long long answer = 0;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			x.push_back(a[i][0] + a[j][1]);
			y.push_back(a[i][2] + a[j][3]);
		}
	}
	sort(x.begin(), x.end());
	sort(y.begin(), y.end());
	for (int i = 0; i < n * n; ++i) {
		answer += upper_bound(y.begin(), y.end(), -x[i]) 
			    - lower_bound(y.begin(), y.end(), -x[i]);
	}
	cout << answer;
}

int main() {
	cin.tie(0), cout.tie(0);
	ios_base::sync_with_stdio(0);
	solution();
	return 0;
}
