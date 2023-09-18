#include <iostream>
#include <string>
using namespace std;
#define MAX 1003005

int n;
bool vis[MAX]{ 1,1 };

void sieve() {
	for (int i = 2; i * i <= MAX; ++i) {
		if (vis[i]) continue;
		for (int j = i * i; j <= MAX; j += i) {
			vis[j] = 1;
		}
	}
}

bool palindrom(int x) {
	string s = to_string(x);
	int len = s.length();
	for (int i = 0; i < len >> 1; ++i) {
		if (s[i] != s[len - 1 - i]) return false;
	}
	return true;
}

void input() {
	cin >> n;
}

void solution() {
	input();
	sieve();
	for (int i = n;; ++i) {
		if (vis[i]) continue;
		if (palindrom(i)) {
			cout << i;
			return;
		}
	}
}

int main(){
    cin.tie(0), cout.tie(0);
    ios_base::sync_with_stdio(0);
    solution();
    return 0;
}
