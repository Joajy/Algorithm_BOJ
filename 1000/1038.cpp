#include<iostream>
#include<queue>
#include<vector>
using namespace std;
#define ll long long

int n;
vector<ll> v;

void input() {
	cin >> n;
}

void rec() {
	queue<ll> q;
	for (int i = 0; i < 10; ++i) {
		q.push(i);
		v.push_back(i);
	}
	while (!q.empty()) {
		ll num = q.front(); q.pop();
		int end = num % 10;
		for (int i = 0; i < end; ++i) {
			//마지막 자릿수는 기존 num의 일의 자리를 넘지 않도록 제한
			ll upper = num * 10 + i;
			q.push(upper);
			v.push_back(upper);
		}
	}
	if (n >= v.size()) {
		cout << -1;
		return;
	}
	cout << v[n];
}

void solution() {
 	input();
	rec();
}

int main() {
	cin.tie(0), cout.tie(0);
	ios_base::sync_with_stdio(0);
	solution();
	return 0;
 }
