#include<iostream>
#define p pair<int, int>
using namespace std;
#define s shark[num]

int n, m, k;
int area[21][21];
p smell[21][21];//first: 번호, second: 남은 횟수(k 시작)
// 1 ~ 4: 상 하 좌 우
int dx[]{ 0,-1,1,0,0 };
int dy[]{ 0,0,0,-1,1 };
bool alive[401];

struct shark {
	int x, y, dir;
	//1 ~ 4: 상 하 좌 우(우선순위)
	int seq[5][5];
}shark[401];

void input() {
	cin >> n >> m >> k;
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= n; ++j) {
			cin >> area[i][j];
			int cur = area[i][j];
			if (cur > 0) {
				smell[i][j] = { cur, k };
				shark[cur].x = i;
				shark[cur].y = j;
			}
		}
	}
	for (int i = 1; i <= m; ++i) {
		cin >> shark[i].dir;
		alive[i] = 1;
	}
	for (int i = 1; i <= m; ++i) {
		for (int j = 1; j <= 4; ++j) {
			for (int z = 1; z <= 4; ++z) {
				cin >> shark[i].seq[j][z];
			}
		}
	}
}

bool checkOnlyOne() {
	for (int i = 2; i <= m; ++i) {
		if (alive[i] == 0) continue;
		return false;
	}
	return true;
}

//방향 전환, 냄새 남기기
void checkCondition(int num) {
	//인접한 칸 중 아무 냄새가 없는 칸 찾기
	for (int i = 1; i <= 4; ++i) {
		//우선순위에 따른 방향 전환
		int nd = s.seq[s.dir][i];
		int nx = s.x + dx[nd];
		int ny = s.y + dy[nd];
		if (nx < 1 || ny < 1 || nx > n || ny > n) continue;
		if (smell[nx][ny].first == 0) {
			//냄새 남기기 -> k + 1인 이유는 전체 이동 후 모든 냄새 위치 --할 예정
			//결국 k초 부여하게 됨
			//현 위치에 남기고 위치 이동
//			smell[nx][ny] = { num, k };
			//상어 이동 정보 업데이트
			s.dir = nd;
			s.x = nx;
			s.y = ny;
			return;
		}
	}
	//내 냄새 있는 방향 확인
	for (int i = 1; i <= 4; ++i) {
		int nd = s.seq[s.dir][i];
		int nx = s.x + dx[nd];
		int ny = s.y + dy[nd];
		if (nx < 1 || ny < 1 || nx > n || ny > n) continue;
		if (smell[nx][ny].first == num) {
			//냄새 남기기 -> k + 1인 이유는 전체 이동 후 모든 냄새 위치 --할 예정
			//결국 k초 부여하게 됨
			//현 위치에 남기고 위치 이동
//			smell[nx][ny] = { num, k };
			//상어 이동 정보 업데이트
			s.dir = nd;
			s.x = nx;
			s.y = ny;
			return;
		}
	}
}

void move() {
	int a[21][21]{ 0 };
	for (int i = 1; i <= m; ++i) {
		if (alive[i] == 0) continue;
		//냄새 뿌리고 가야함(k+1로 뿌리고 전체 칸 --할 예정)
		checkCondition(i);
		int nx = shark[i].x, ny = shark[i].y;
		//번호 더 작은 친구가 해당 칸으로 이동 시
		if (a[nx][ny] > i) {
			//기존에 있던 친구 삭제(alive[] == 0)
			alive[a[nx][ny]] = 0;
			//해당 위치 새로운 친구가 들어감
			a[nx][ny] = i;
		}
		//빈 칸일 경우
		else if (a[nx][ny] == 0) {
			//해당 위치 새로운 친구가 들어감
			a[nx][ny] = i;
		}
		else if (a[nx][ny] < i) {
			alive[i] = 0;
		}
	}
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= n; ++j) {
			area[i][j] = a[i][j];
		}
	}
	for (int i = 1; i <= m; ++i) {
		if (alive[i] == 0) continue;
		smell[shark[i].x][shark[i].y] = { i, k + 1 };
	}
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= n; ++j) {
			if (smell[i][j].first == 0 || smell[i][j].second == 0) continue;
			if (--smell[i][j].second == 0) {
				smell[i][j].first = 0;
			}
		}
	}
}

void solution() {
	input();
	for (int i = 1; i <= 1000; ++i) {
		move();
		//1번 상어만 격자에 남는 경우
		if (checkOnlyOne()) {
			cout << i;
			return;
		}
	}
	cout << -1;
}


int main() {
	cin.tie(0), cout.tie(0);
	ios_base::sync_with_stdio(0);
	solution();
	return 0;
}
