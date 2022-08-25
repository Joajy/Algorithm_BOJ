#include<iostream>
#define fast cin.tie(0), cout.tie(0), ios::sync_with_stdio(0);
using namespace std;

bool a[10002];

int main() {
	fast;
	int t, n, cnt = 0;
	for (int i = 2; i <= 10000; i++) {
		if (a[i] == 1) continue;		
		for (int j = 2 * i; j <= 10000; j += i)	
			a[j] = 1; 
	}
	cin >> t;
	while (t--) {
		int min_dif1 = 10000, min_dif2 = 0;
		cin >> n;
		for (int i = n; i >= 2; i--) {
			if (!a[i] && !a[n - i] && min_dif1 - min_dif2 > n - 2 * i) {
				min_dif2 = n - i;
				min_dif1 = i;
			}
		}
		cout << min_dif2 << ' ' << min_dif1 << '\n';
	}
	return 0;
}
