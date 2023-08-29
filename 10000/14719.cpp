#include<iostream>
#include<vector>
using namespace std;

int h, w, answer = 0;
vector<int> v[501];

void input() {
	cin >> h >> w;
	answer = 0;
	int num;
	for (int i = 1; i <= w; ++i) {
		cin >> num;
		for (int j = 1; j <= num; ++j) {
			v[j].push_back(i);
		}
	}
}

void solution() {
	input();
	for (int i = h; i >= 1; --i) {
		if (v[i].size() < 2) {
			continue;
		}
		int cur = v[i][0], range = 0;
		for (int j = 1; j < v[i].size(); ++j) {
			range += v[i][j] - cur - 1;
			cur = v[i][j];
		}
		answer += range;
	}
	cout << answer;
}

int main() {
	cin.tie(0), cout.tie(0);
	ios_base::sync_with_stdio(0);
	solution();
	return 0;
} 
