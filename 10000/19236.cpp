#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#define p pair<int ,int>
#define X first
#define Y second

struct FISH {
	int r, c, d;
	bool alive;
	FISH() {
		r = c = d = 0;
	}
	FISH(int r, int c, int d, bool alive) {
		this->r = r;
		this->c = c;
		this->d = d;
	}
};

int x, y, ans = 0;
FISH fish[17];
int a[4][4]; // initial Number
int dx[8]{ -1,-1,0,1,1,1,0,-1 };
int dy[8]{ 0,-1,-1,-1,0,1,1,1 };

void input() {
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			cin >> x >> y;
			fish[x] = FISH(i, j, y - 1, true);
			a[i][j] = x;
		}
	}
}

void dfs(int temp[4][4], FISH prvFish[], p cur, int sum) {
	//setting
	int tmp[4][4];
	for (int i = 0; i < 4; i++) for (int j = 0; j < 4; j++) tmp[i][j] = temp[i][j];
	FISH copyFish[17];
	for (int i = 1; i <= 16; i++) copyFish[i] = prvFish[i];

	//eat fish
	int pray = tmp[cur.X][cur.Y];
	int sDir = copyFish[pray].d;
	copyFish[pray].alive = false;
	copyFish[pray].r = -1;
	copyFish[pray].c = -1;
	tmp[cur.X][cur.Y] = 0;
	

	//sum of eaten fish's number
	sum += pray;
	if (sum > ans) ans = sum;

	//move each fish order by number
	for (int i = 1; i <= 16; i++) {
		if (copyFish[i].r == -1) continue;

		p curF = { copyFish[i].r, copyFish[i].c };
		int curDir = copyFish[i].d;

		p nxtF = { curF.X + dx[curDir], curF.Y + dy[curDir] };
		int nxtDir = curDir;

		while (nxtF.X < 0 || nxtF.X >= 4 || nxtF.Y < 0 || nxtF.Y >= 4 || nxtF == cur) {
			nxtDir = (nxtDir + 1) % 8;
			nxtF = { curF.X + dx[nxtDir], curF.Y + dy[nxtDir] };
		}

		//if target position is safe(non-shark)
		if (tmp[nxtF.X][nxtF.Y] > 0) {
			int targNum = tmp[nxtF.X][nxtF.Y];

			//exchange targetFish with currentFish
			copyFish[targNum].r = curF.X;
			copyFish[targNum].c = curF.Y;

			copyFish[i].r = nxtF.X;
			copyFish[i].c = nxtF.Y;
			copyFish[i].d = nxtDir;

			tmp[nxtF.X][nxtF.Y] = i;
			tmp[curF.X][curF.Y] = targNum;
		}
		//if target position is safe(blank)
		else {
			copyFish[i].r = nxtF.X;
			copyFish[i].c = nxtF.Y;
			copyFish[i].d = nxtDir;

			tmp[nxtF.X][nxtF.Y] = i;
			tmp[curF.X][curF.Y] = 0;
		}
	}
	for (int i = 1; i <= 3; i++) {
		int nx = cur.X + dx[sDir] * i;
		int ny = cur.Y + dy[sDir] * i;

		if (nx < 0 || nx >= 4 || ny < 0 || ny >= 4) break;
		if (tmp[nx][ny] > 0) dfs(tmp, copyFish, { nx, ny }, sum);
	}
}


void solution() {
	input();
	dfs(a, fish, { 0,0 }, 0);
	cout << ans;
}

int main() {
	cin.tie(0);
	ios::sync_with_stdio(0);
	solution();
	return 0;
}
