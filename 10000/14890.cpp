#include<iostream>
#include<cstring>
using namespace std;

int n, l;
int a[101][101];
int vis[101][101]{ 0 };
int dx[]{ 0,0,-1,1 };
int dy[]{ 1,-1,0,0 };

void input() {
	cin >> n >> l;
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= n; ++j) {
			cin >> a[i][j];
		}
	}
}

bool x(int i) {
	for (int j = 1; j < n; ++j) {
		if (a[i][j + 1] == a[i][j]) continue;
		//낮은 칸과 높은 칸의 높이 차이가 1이 아닌 경우
		if (a[i][j] - a[i][j + 1] > 1 || a[i][j + 1] - a[i][j] > 1) {
			return false;
		}
		//경사로를 놓다가 범위를 벗어나는 경우
		if (a[i][j] < a[i][j + 1] && j < l) {
			return false;
		}
		else if (a[i][j] > a[i][j + 1] && j + l > n) {
			return false;
		}
		//낮은 지점의 칸의 높이가 모두 같지 않거나, L개가 연속되지 않은 경우
		//경사로를 놓은 곳에 또 경사로를 놓는 경우
		if (a[i][j] > a[i][j + 1]) {	//왼쪽이 더 큰 경우 오른쪽에 경사로
			if (l == 1) {
				vis[i][j + 1] = 1;
				continue;
			}
			for (int x = 1; x <= l; ++x) {
				if (a[i][j + 1] != a[i][j + x] || vis[i][j + x] == 2) {
					return false;
				}
				vis[i][j + x] = 1;
			}
			j += l - 1;
		}
		else {	//오른쪽이 더 큰 경우 왼쪽으로 경사로
			if (l == 1) {
				if (vis[i][j] == 1) {
					return false;
				}
				vis[i][j] = 2;
				continue;
			}
			for (int x = 0; x < l; ++x) {
				if (a[i][j] != a[i][j - x] || vis[i][j - x] == 1) {
					return false;
				}
				vis[i][j - x] = 2;
			}
		}
	}
	if (a[i][n - 1] - a[i][n] > 1 || a[i][n] - a[i][n - 1] > 1) return false;
	return true;
}

bool y(int j) {
	for (int i = 1; i < n; ++i) {
		if (a[i + 1][j] == a[i][j]) continue;
		//낮은 칸과 높은 칸의 높이 차이가 1이 아닌 경우
		if (a[i][j] - a[i + 1][j] > 1 || a[i + 1][j] - a[i][j] > 1) {
			return false;
		}
		//경사로를 놓다가 범위를 벗어나는 경우
		if (a[i][j] < a[i + 1][j] && i < l) {
			return false;
		}
		else if (a[i][j] > a[i + 1][j] && i + l > n) {
			return false;
		}
		//낮은 지점의 칸의 높이가 모두 같지 않거나, L개가 연속되지 않은 경우
		//경사로를 놓은 곳에 또 경사로를 놓는 경우
		if (a[i][j] > a[i + 1][j]) {	//왼쪽이 더 큰 경우 오른쪽에 경사로
			if (l == 1) {
				vis[i + 1][j] = 1;
				continue;
			}
			for (int x = 1; x <= l; ++x) {
				if (a[i + 1][j] != a[i + x][j] || vis[i + x][j] == 2) {
					return false;
				}
				vis[i + x][j] = 1;
			}
			i += l - 1;
		}
		else {	//오른쪽이 더 큰 경우 왼쪽으로 경사로
			if (l == 1) {
				if (vis[i][j] == 1) {
					return false;
				}
				vis[i][j] = 2;
				continue;
			}
			for (int x = 0; x < l; ++x) {
				if (a[i][j] != a[i - x][j] || vis[i - x][j] == 1) {
					return false;
				}
				vis[i - x][j] = 2;
			}
		}
	}
	if (a[n - 1][j] - a[n][j] > 1 || a[n][j] - a[n - 1][j] > 1) return false;
	return true;
}

void solution() {
	input();
	int answer = 0;
	bool fin;
	//세로
	for (int i = 1; i <= n; ++i) {
		if (x(i)) ++answer;
	}
	//가로
	memset(vis, 0, sizeof(vis));
	for (int i = 1; i <= n; ++i) {
		if (y(i)) ++answer;
	}
	cout << answer;
}

int main() {
	cin.tie(0), cout.tie(0);
	ios_base::sync_with_stdio(0);
	solution();
	return 0;
}
