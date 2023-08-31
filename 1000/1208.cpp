#include<iostream>
#include<map>

using namespace std;

int n, s, mid;
long long answer = 0;
int a[40];
map<int, int> m;

void input() {
	cin >> n >> s;
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
	}
	mid = n >> 1;
}

void leftSum(int cur, int sum) {
	if (cur == mid) {
		++m[sum];
		return;
	}
	leftSum(cur + 1, sum);
	leftSum(cur + 1, sum + a[cur]);
}

void rightSum(int cur, int sum) {
	if (cur == n) {
		answer += m[s - sum];
		return;
	}
	rightSum(cur + 1, sum);
	rightSum(cur + 1, sum + a[cur]);
}

void solution() {
	input();
	leftSum(0, 0);
	rightSum(mid, 0);

	if (s == 0) --answer;
	cout << answer;
}

int main() {
	cin.tie(0), cout.tie(0);
	ios_base::sync_with_stdio(0);
 	solution();
	return 0;
}
