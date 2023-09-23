#include<iostream>
#include<vector>
using namespace std;

int n, answer = 0;
int a[101][101];
int dx[]{ 0,-1,0,1 };
int dy[]{ 1,0,-1,0 };
 
void input() {
	cin >> n;
}

void solution() {
//	input();
	cin >> n;
	int x, y, d, g;
	for (int i = 0; i < n; ++i) {
		cin >> y >> x >> d >> g;
		vector<int> seq;
		seq.push_back(d);
		while(g--) {
			int num, size = seq.size();
			for (int j = 0; j < size; ++j) {
				num = seq[size - j - 1];
				seq.push_back((num + 1) % 4);
			}
		}
		a[x][y] = 1;
		for (int dir : seq) {
			x += dx[dir];
			y += dy[dir];
			a[x][y] = 1;
		}
	}
	for (int i = 0; i < 100; ++i) {
		for (int j = 0; j < 100; ++j) {
			if (a[i][j] == 0 || a[i + 1][j + 1] == 0) continue;
			if (a[i + 1][j] == 0 || a[i][j + 1] == 0) continue;
			++answer;
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
