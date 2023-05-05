#include<iostream>
using namespace std;

int n, answer = 0;
int queen[15];

int abs(int a){
    if(a < 0) return -a;
    return a;    
}

void dfs(int row) {
	if (n == row) {
		++answer;
		return;
	}
	for (int i = 0; i < n; ++i) {
		queen[row] = i;
		bool more = true;
		for (int j = 0; j < row; ++j) {
			if (abs(queen[j] - queen[row]) == row - j) more = false;
			if (queen[row] == queen[j]) more = false;
		}
		if (more) dfs(row + 1);
	}
}

void solution() {
	cin >> n;
	dfs(0);
	cout << answer;
}

int main() {
	cin.tie(0), cout.tie(0), ios_base::sync_with_stdio(0);
	solution();
	return 0;
}
