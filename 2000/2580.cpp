#include <iostream>
#include <vector>
using namespace std;
#define n 9
#define p pair<int, int>

int sq[n][n];
vector<p> v;
bool already = 0;

void init() {
	for (int i = 0; i < n; ++i) {
		bool vis[10]{ 0 };
		for (int j = 0; j < n; ++j) {
			cin >> sq[i][j];
			if (sq[i][j] == 0) v.push_back({ i,j });
		}
	}
}

bool inSquare(p nxt) {
	p correction = p((nxt.first / 3) * 3, (nxt.second / 3) * 3);
	int x = correction.first, y = correction.second;
	for (int i = x; i < x + 3; ++i) {
		for (int j = y; j < y + 3; ++j) {
			if (sq[nxt.first][nxt.second] == sq[i][j] && p(i, j) != nxt) return 0;
		}
	}
	return 1;
}

bool inRow(p nxt) {
	for (int j = 0; j < n; ++j) {
		if (sq[nxt.first][nxt.second] == sq[nxt.first][j] && nxt.second != j) return 0;
	}
	return 1;
}

bool inCol(p nxt) {
	for (int j = 0; j < n; ++j) {
		if (sq[nxt.first][nxt.second] == sq[j][nxt.second] && nxt.first != j) return 0;
	}
	return 1;
}

bool check(p nxt) {
	return inRow(nxt) && inCol(nxt) && inSquare(nxt);
}

void bt(int cnt) {
	if (cnt == v.size()) {
		//9x9가 문제없이 가능한 경우
		already = 1;
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < n; ++j) {
				cout << sq[i][j] << " ";
			}
			cout << '\n';
		}
		return;
	}
	p nxt = v[cnt];
	for (int j = 1; j <= n; ++j) {
		sq[nxt.first][nxt.second] = j;
		if (!check(nxt)) continue;
		bt(cnt + 1);
		if (already) return;
	}
	sq[nxt.first][nxt.second] = 0;
}

void solution() {
	init();
	bt(0);
}

int main() {
	cin.tie(0), cout.tie(0);
	ios_base::sync_with_stdio(0);
	solution();
	return 0;
}
