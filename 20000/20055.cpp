#include<iostream>
using namespace std;

int n, k, cnt = 0, answer = 0;
int a[201];
bool r[201]{ 0 };

void input() {
	cin >> n >> k;
	for (int i = 1; i <= (n << 1); ++i) {
		cin >> a[i];
		if (a[i] == 0) ++cnt;
	}
}

void solution() {
	input();
	if (k <= cnt) {
		cout << 1;
		return;
	}
	while (k > cnt) {
		//1. 벨트, 로봇 회전
		int tmp = a[n << 1];
		for (int i = 2 * n; i > 1; --i) {
			a[i] = a[i - 1];
		}
		for (int i = n; i >= 1; --i) {
			r[i] = r[i - 1];
		}
		a[1] = tmp;
		r[1] = r[n] = 0;
		//2. 로봇 이동
		for (int i = n; i > 1; --i) {
			if (r[i - 1] == 0) continue;
			if (r[i] == 0 && a[i] > 0) {
				r[i - 1] = 0;
				r[i] = 1;
				if (--a[i] == 0) ++cnt;
			}
		}
		//3. 올리는 위치[1]에 로봇 올리기
		if (a[1] > 0 && r[1] == 0) {
			r[1] = 1;
			if (--a[1] == 0) ++cnt;
		}
		++answer;
	}
	cout << answer;
}

int main() {
	cin.tie(0);
	cout.tie(0);
	ios_base::sync_with_stdio(0);
	solution();
	return 0;
}
