#include<iostream>
#define fast cin.tie(0), cout.tie(0), ios::sync_with_stdio(0);
using namespace std;

bool a[1000002];

int main() {
	fast;
	int n = 0, cnt = 0;
	for (int i = 2; i <= 1000000; i++) {
		if (a[i] == 1) continue;		
		for (int j = 2 * i; j <= 1000000; j += i)
			a[j] = 1;	
	}
	a[2] = 1;
	while (cin >> n) {
		if (n == 0) break;
		bool check = 0;
		//1000000, 999999, 999998 is not primeNum, Only OddNum use
		for (int i = n - 3; i > 2; i -= 2) {
			if (!a[i] && !a[n - i]) {
				cout << n << " = " << n - i << " + " << i << '\n';
				check = 1;
				break;
			}
		}
		if(!check)
			cout << "Goldbach's conjecture is wrong\n";
	}
	return 0;
}
