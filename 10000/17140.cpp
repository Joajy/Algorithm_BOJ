#include<iostream>
#include<algorithm>
#include<queue>
#define p pair<int, int>
using namespace std;

int a[101][101], answer = 1e9;
int r, c, k, row = 3, col = 3;

void input() {
	cin >> r >> c >> k;
	for (int i = 1; i <= 3; ++i) {
		for (int j = 1; j <= 3; ++j) {
			cin >> a[i][j];
		}
	}
}

void query(int cnt) {
	if (cnt > 100) {
		answer = -1;
		return;
	}
	if (a[r][c] == k) {
		answer = cnt;
		return;
	}
	priority_queue<p> q;
	if (row >= col) {
		col = 0;
		for (int i = 1; i <= row; ++i) {
			int tmp[101]{ 0 };
			for (int j = 1; j <= 100; ++j) {
                ++tmp[a[i][j]];
            }
			for (int j = 1; j <= 100; ++j) {
                if (tmp[j] == 0) continue;
                q.push({ -tmp[j], -j });	//cnt, number
		    }
			int idx = 1;
			while (!q.empty()) {
				a[i][idx] = -q.top().second;
				a[i][idx + 1] = -q.top().first; q.pop();
				idx += 2;
			}
			for (int x = idx; x <= 100; ++x) {
				a[i][x] = 0;
			}
			if (--idx > col) col = idx;
		}
	}
	else {	//row < col
		row = 0;
		for (int i = 1; i <= col; ++i) {
			int tmp[101]{ 0 };
			for (int j = 1; j <= 100; ++j) {
                ++tmp[a[j][i]];
            }
			for (int j = 1; j <= 100; ++j) {
                if (tmp[j] == 0) continue;
                q.push({ -tmp[j], -j });	//cnt, number
    			}
			int idx = 1;
			while (!q.empty()) {
				a[idx][i] = -q.top().second;
				a[idx + 1][i] = -q.top().first; q.pop();
				idx += 2;
			}
			for (int x = idx; x <= 100; ++x) {
				a[x][i] = 0;
			}
			if (--idx > row) row = idx;
		}
	}
	query(cnt + 1);
}

void solution() {
	input();
	query(0);
	cout << answer;
}

int main() {
	cin.tie(0), cout.tie(0);
	ios_base::sync_with_stdio(0);
	solution();
	return 0;
}
