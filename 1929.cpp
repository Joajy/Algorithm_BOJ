#include<iostream>
#define fast cin.tie(0), cout.tie(0), ios::sync_with_stdio(0)
using namespace std;
int ar[1000001]{ 0,0,0,0 };
int main() {
	int m, n;
	cin >> m >> n;
	for (int i = 2; i <= n; i++)		ar[i] = i;
	for (int i = 2; i <= n; i++) {
		if (ar[i] == 0) continue;
		for (int j = 2 * i; j <= n; j+=i) {
			ar[j] = 0;
		}
	}
	for (int i = m; i <= n; i++) {
		if(ar[i] != 0)
			cout << ar[i] << '\n';
	}
	return 0;
}