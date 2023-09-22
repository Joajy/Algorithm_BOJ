#include<iostream>
using namespace std;

int k, answer = 0;
int a[5][8];

void input() {
	string s;
	for (int i = 1; i <= 4; ++i) {
		cin >> s;
		for (int j = 0; j < (int)s.length(); ++j) {
			a[i][j] = s[j] - '0';
		}
	}
	cin >> k;
}

void normal(int num) {
	int tmp[8];
	for (int i = 0; i < 8; ++i) {
		tmp[(i + 1) % 8] = a[num][i];
	}
	for (int i = 0; i < 8; ++i) {
		a[num][i] = tmp[i];
	}
}

void abnormal(int num) {
	int tmp[8];
	for (int i = 0; i < 8; ++i) {
		tmp[(i + 7) % 8] = a[num][i];
	}
	for (int i = 0; i < 8; ++i) {
		a[num][i] = tmp[i];
	}
}

void query(int num, int dir) {
	if (dir == 1) {
		normal(num);
	}
	else {
		abnormal(num);
	}
}

void rotate(int num, int dir) {
	int left = a[num][6], right = a[num][2];
	switch (num) {
	case 1:
		query(1, dir);
		if (right == a[2][6]) break;
		right = a[2][2];
		query(2, -dir);
		if (right == a[3][6]) break;
		right = a[3][2];
		query(3, dir);
		if (right == a[4][6]) break;
		query(4, -dir);
		break;
	case 2:
		query(2, dir);
		if (left != a[1][2]) {
			query(1, -dir);
		}
		if (right == a[3][6]) break;
		right = a[3][2];
		query(3, -dir);
		if (right == a[4][6]) break;
		query(4, dir);
		break;
	case 3:
		query(3, dir);
		if (right != a[4][6]) {
			query(4, -dir);
		}
		if (left == a[2][2]) break;
		left = a[2][6];
		query(2, -dir);
		if (left == a[1][2]) break;
		query(1, dir);
		break;
	case 4:
		query(4, dir);
		if (left == a[3][2]) break;
		left = a[3][6];
		query(3, -dir);
		if (left == a[2][2]) break;
		left = a[2][6];
		query(2, dir);
		if (left == a[1][2]) break;
		query(1, -dir);
	}
}

void solution() {
	input();
	int num, dir;
	for (int i = 0; i < k; ++i) {
		cin >> num >> dir;
		rotate(num, dir);
	}
	for (int i = 0; i < 4; ++i) {
		if (a[i + 1][0] == 1) {
			answer += (1 << i);
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
