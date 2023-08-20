#include<iostream>
#include<vector>
using namespace std;
#define ll long long

int n;
ll minVal = 9876543210, maxVal = 0;
bool maxSt0 = 0, minSt0 = 0;
char a[10];

void input() {
	cin >> n;
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
	}
}

ll pow(int cnt, int val) {
	ll ret = val;
	for (int i = 0; i < cnt; ++i) {
		ret *= 10;
	}
	return ret;
}

void bt(vector<int> v, bool vis[], int idx) {
	if ((int)v.size() == n + 1) {
		ll tmp = 0;
		for (int i = 0; i < (int)v.size(); ++i) {
			tmp += pow((int)v.size() - i - 1, v[i]);
		}
		if (tmp < minVal) {
			if (v[0] == 0) minSt0 = 1;
			else minSt0 = 0;
			minVal = tmp;
		}
		if (tmp > maxVal) {
			if (v[0] == 0) maxSt0 = 1;
			else maxSt0 = 0;
			maxVal = tmp;
		}
		return;
	}
	for (int i = 0; i <= 9; ++i) {
		if (vis[i]) continue;
		if ((v.back() > i && a[idx] == '>') || (v.back() < i && a[idx] == '<')) {
			vis[i] = 1;
			v.push_back(i);
			bt(v, vis, idx + 1);
			v.erase(v.end() - 1);
			vis[i] = 0;
		}
	}
}

void solution() {
	input();
	bool vis[10]{ 0 };
	vector<int> v;
	for (int i = 0; i <= 9; ++i) {
		vis[i] = 1;
		v.push_back(i);
		bt(v, vis, 0);
		v.clear();
		vis[i] = 0;
	}
	if (maxSt0) cout << 0;
	cout << maxVal << '\n';
	if (minSt0) cout << 0;
	cout << minVal;
}

int main() {
	cin.tie(0), cout.tie(0);
	ios_base::sync_with_stdio(0);
	solution();
	return 0;
}
