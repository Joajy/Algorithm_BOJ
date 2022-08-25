#include<iostream>
#define fast cin.tie(0), cout.tie(0), ios::sync_with_stdio(0);
using namespace std;

int a[250000];

int main() {
	fast;
	int n;
	for (int i = 1; i <= 2 * 123456; i++)		
        a[i] = i;
	for (int i = 2; i <= 2 * 123456; i++) {		
        if (a[i] == 0) continue;		
        for (int j = 2 * i; j <= 2 * 123456; j += i)	
            a[j] = 0;	
    }
	while (cin >> n) {
		if (n == 0) return 0;
		int ans = 0;
		for (int i = n + 1; i <= 2 * n; i++)
			if (a[i] != 0)
				ans++;
		cout << ans << '\n';
	}
	return 0;
}
