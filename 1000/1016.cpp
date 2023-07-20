#include<iostream>
#include<cmath>
using namespace std;
#define ll long long

ll minN, maxN;
int sieve[1'000'001]{ 0 };

void input() {
	cin >> minN >> maxN;
}

void makeSieve() {
	for (ll i = 2; i * i <= maxN; ++i) {
		ll sq = i * i;
		ll num = minN / sq;
		if (num * sq < minN) ++num;
		while (num * sq <= maxN) {
			++sieve[num * sq - minN];
			++num;
		}
	}
}

void solution() {
	input();
	makeSieve();
	int answer = 0;
	for (int i = 0; i <= maxN - minN; ++i) {
		if (sieve[i] == 0) ++answer;
	}
	cout << answer;
}

int main() {
	cin.tie(0), cout.tie(0);
	ios_base::sync_with_stdio(0);
	solution();
	return 0;
}
