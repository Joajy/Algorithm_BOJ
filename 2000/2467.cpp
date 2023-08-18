#include<iostream>
#include<cmath>
using namespace std;

int n;
int a[100001];	

void input() {
	cin >> n;
	for (int i = 1; i <= n; ++i) {
		cin >> a[i];
	}
}

void solution() {
	input();
	int dif = 2e9 + 1;
	int bestL, bestR;
	int l = 1, r = n;
	while (l < r) {
		int cmp = a[l] + a[r];
		if (abs(cmp) < abs(dif)) {
			dif = cmp;
			bestL = a[l], bestR = a[r];
		}
        if (cmp > 0) --r;
		else ++l;
	}
	cout << bestL << ' ' << bestR;
}

int main() {
	cin.tie(0), cout.tie(0);
	ios_base::sync_with_stdio(0);
	solution();
	return 0;
}
