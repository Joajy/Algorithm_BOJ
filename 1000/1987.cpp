#include<iostream>
using namespace std;

string area[21];
int dx[]{ 0,1,0,-1 };
int dy[]{ 1,0,-1,0 };
bool alp[26];
int r, c, answer = 0;
const char OFFSET = 'A';

void dfs(int x, int y, int dist) {
	if (answer < dist) answer = dist;
	for (int dir = 0; dir < 4; dir++) {
		int nx = x + dx[dir];
		int ny = y + dy[dir];

		if (nx < 0 || ny < 0 || nx >= r || ny >= c) continue;
		int index = area[nx][ny] - OFFSET;
		if (alp[index])continue;
		alp[index] = 1;
		dfs(nx, ny, dist + 1);
		alp[index] = 0;
	}

}

void input() {
	cin >> r >> c;
	for (int i = 0; i < r; ++i) cin >> area[i];
}

void solution() {
	input();
	alp[area[0][0] - OFFSET] = 1;
	dfs(0, 0, 1);
	cout << answer;
}

int main() {
	cin.tie(0), cout.tie(0), ios_base::sync_with_stdio(0);
	solution();
	return 0;
}
