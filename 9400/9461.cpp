#include<iostream>
#include<vector>
using namespace std;
int main() {
	int t, n;
	cin >> t;
	while (t--) {
		//set new vector in each case
		vector<long long> v = { 1,1,1,2,2,3,4,5,7,9 };
		cin >> n;
		if (n <= 10) {
			cout << v.at(n - 1) << '\n';
			continue;
		}
		//p[n] = p[n - 1] + p[n - 5]
		for (int i = 10; i < n; i++) {
			long long x = v.at(i - 1) + v.at(i - 5);
			v.push_back(x);
		}
		cout << v.at(n - 1) << '\n';
	}
	return 0;
} 
