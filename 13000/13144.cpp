#include<iostream>
#include<cstring>
using namespace std;

int n;
int a[100001];
bool vis[100001]{ 0 };

void input() {
	cin >> n;
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
	}
}

void solution() {
	input();
	int en = 0;
  long long answer = 0;
	for (int st = 0; st < n; ++st) {
		while (en < n) {
			if (vis[a[en]]) break;
			vis[a[en++]] = 1;
		}
		answer += en - st;
		vis[a[st]] = 0;
	}
	cout << answer;
}

int main() {
	cin.tie(0), cout.tie(0), ios_base::sync_with_stdio(0);
	solution();
	return 0;
}
