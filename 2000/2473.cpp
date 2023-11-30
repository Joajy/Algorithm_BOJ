#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;
#define ll long long

int n;
ll answer = 1e10;
vector<ll> liq;

void input() {
	cin >> n;
	ll num;
	for (int i = 0; i < n; ++i) {
		cin >> num;
		liq.push_back(num);
	}
}

void solution() {
	input();
	vector<ll> ans(3);
	sort(liq.begin(), liq.end());
	for (int i = 0; i < n - 2; ++i) {
		int st = i + 1;
		int en = n - 1;
		while (st < en) {
			ll sum = liq[i] + liq[st] + liq[en];
			if (abs(answer) > abs(sum)) {
				answer = sum;
				ans[0] = liq[i];
				ans[1] = liq[st];
				ans[2] = liq[en];
			}
			if (sum == 0) break;
			else if (sum > 0) --en;
			else ++st;
		}
	}
	for (int i : ans) {
		cout << i << " ";
	}
}

int main(){
	cin.tie(0), cout.tie(0);
	ios_base::sync_with_stdio(0);
	solution();
	return 0;
}
