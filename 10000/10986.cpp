#include<iostream>
using namespace std;
#define ll long long

int n, m, cnt = 0;
ll prefix[1001];

void input() {
	cin >> n >> m;
	int num;
	for (int i = 1; i <= n; ++i) {
		cin >> num;
		cnt = (cnt + num) % m;
		++prefix[cnt];
	}
}

void solution() {
	input();
	ll answer = 0;
	for (int i = 0; i < m; ++i) {
		//nC2, n개중에 2개를 순서 상관없이 선택
		answer += (prefix[i] * (prefix[i] - 1)) >> 1;
	}
	cout << answer + prefix[0];
}

int main() {
	cin.tie(0), cout.tie(0);
	ios_base::sync_with_stdio(0);
	solution();
	return 0;
} 
