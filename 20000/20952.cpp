#include <iostream>
using namespace std;
#define p pair<int, int>
#define DIV 1'000'000'007

int n, m, totalSum = 0, totalCnt = 0;
int a[100001], b[100001];
int cnt[8]{0};

void input() {
	cin >> n >> m;
	for (int i = 1; i <= n; ++i) {
		cin >> a[i];
		int div = a[i] % 7;
		if (div == 0) ++cnt[7];
		else ++cnt[div];
	}
	for (int i = 1; i <= m; ++i) {
		cin >> b[i];
	}
	totalCnt = n;
}

void solution() {
	input();
	int del = 0;
	for (int i = 1; i <= m; ++i) {
        //연산 시 수열 A의 모든 원소 제거되는 경우에는 생략 
		if (totalCnt <= cnt[7 - (del + b[i]) % 7]) continue;
		del = (del + b[i]) % 7;
		totalCnt -= cnt[7 - del];
		cnt[7 - del] = 0;
        //성공한 연산은 누적하여 최종값에서 덧셈할 예정
		totalSum = (totalSum + b[i]) % DIV;
	}
	cout << totalCnt << '\n';
	for (int i = 1; i <= n; ++i) {
		int x = a[i] % 7;
		if (x == 0) x = 7;
        //이미 지워진 값(7의 배수였던 적이 있을 경우)은 출력 X
		if (cnt[x] == 0) continue;
		cout << (a[i] + totalSum) % DIV << ' ';
	}
}

int main() {
	cin.tie(0), cout.tie(0);
	ios_base::sync_with_stdio(0);
	solution();
	return 0;
}
