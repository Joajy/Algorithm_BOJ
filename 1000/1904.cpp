#include<iostream>
#include<vector>
using namespace std;
#define ll long long

int n;

void solution() {
	vector<ll> answer{0,1,2};
	cin >> n;
	long long a;
	for (int i = 3; i <= n; ++i) {
		a = answer[i - 1] + answer[i - 2];
		answer.push_back(a % 15746);
	}
	cout << answer[n];
}

int main() {
	cin.tie(0), cout.tie(0);
	ios_base::sync_with_stdio(0);
	solution();
	return 0;
}
