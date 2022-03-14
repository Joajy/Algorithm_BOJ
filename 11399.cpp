#include<iostream>
#include<algorithm>
using namespace std;

int x[1002];

int main() {
	int n;
	cin >> n;
	
	for (int i = 0; i < n; i++) cin >> x[i];
	
	sort(x, x + n);
	int sum = x[0];
	for (int i = 1; i < n; i++) {
		x[i] += x[i - 1];
		sum += x[i];
	}
	cout << sum;

	return 0;
}