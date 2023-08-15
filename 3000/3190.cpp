#include<iostream>
#include<queue>
using namespace std;
#define p pair<int, int>

int n, k, l, x, dir = 0, answer = 0;
char c;
int area[101][101];
int dx[]{ 0,1,0,-1 };
int dy[]{ 1,0,-1,0 };

void input() {
	cin >> n >> k;
	for (int i = 0;i < k;++i) {
		int a, b;
		cin >> a >> b;
		area[a][b] = 2;
	}
	cin >> l;
}

void solution() {
	input();
	queue<p> time;
	deque<p> snake;
	snake.push_back({ 1, 1 });
	area[1][1] = 1;
	for (int i = 0;i < l;++i) {
		cin >> x >> c;
		time.push({ x,c });
	}
	while (1) {
		++answer;
		int nx = snake.front().first + dx[dir];
		int ny = snake.front().second + dy[dir];
		if (nx < 1 || ny < 1 || nx > n || ny > n || area[nx][ny] == 1) break;
		snake.push_front({ nx,ny });
		if (area[nx][ny] != 2) {
			area[snake.back().first][snake.back().second] = 0;
			snake.pop_back();
		}
		area[nx][ny] = 1;
		if (time.empty()) continue;
		if (answer == time.front().first) {
			if (time.front().second == 'L') dir = (dir + 3) % 4;
			else dir = (dir + 1) % 4;
			time.pop();
		}
	}
	cout << answer;
}

int main() {
	cin.tie(0);  cout.tie(0);
	ios_base::sync_with_stdio(0);
	solution();
	return 0;
}
