#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;
int n, m, k;
int a[11][11];
int dx[]{ -1,-1,-1,0,0,1,1,1 };
int dy[]{ -1,0,1,-1,1,-1,0,1 };
vector<int> v[11][11];

struct Tree {
	//나이
	vector<int> deadTree;
	vector<int> alive;
	//양분
	int adder = 5;
	//spring
	void addAge(int x, int y) {
		vector<int> left, right;
		for (int i = alive.size() - 1; i >= 0; --i) {
			if (adder >= alive[i]) {
				adder -= alive[i];
				left.push_back(alive[i] + 1);
			}
			else {
				right.push_back(alive[i]);
			}
		}
		reverse(left.begin(), left.end());
		alive = left;
		deadTree = right;
	}
	//summer
	void changeAdder() {
		for (int i : deadTree) {
			adder += (i >> 1);
		}
		deadTree.clear();
	}
	//autumn
	void spread(int x, int y) {
		for (int i = 0; i < alive.size(); ++i) {
			if (alive[i] % 5 != 0) continue;
			for (int dir = 0; dir < 8; ++dir) {
				int nx = x + dx[dir];
				int ny = y + dy[dir];
				if (nx < 1 || ny < 1 || nx > n || ny > n) continue;
				v[nx][ny].push_back(1);
			}
		}
	}
	//winter
	void fillAdder(int x, int y) {
		adder += a[x][y];
	}
}area[11][11];


void input() {
	cin >> n >> m >> k;
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= n; ++j) {
			cin >> a[i][j];
		}
	}
	int x, y, z;
	for (int i = 0; i < m; ++i) {
		cin >> x >> y >> z;
		area[x][y].alive.push_back(z);
	}
}

void solution() {
	input();
	int answer = 0;
	while(k--) {
		for (int i = 1; i <= n; ++i) {
			for (int j = 1; j <= n; ++j) {
				area[i][j].addAge(i, j);
				area[i][j].changeAdder();
				area[i][j].spread(i, j);
				area[i][j].fillAdder(i, j);
			}
		}
		for (int i = 1; i <= n; ++i) {
			for (int j = 1; j <= n; ++j) {
				area[i][j].alive.insert(area[i][j].alive.end(), v[i][j].begin(), v[i][j].end());
				v[i][j].clear();
			}
		}
	}
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= n; ++j) {
			answer += area[i][j].alive.size();
		}
	}
	cout << answer;
}

int main() {
	cin.tie(0), cout.tie(0);
	ios_base::sync_with_stdio(0);
	solution();
	return 0;
}
