#include<iostream>
#include<vector>
using namespace std;

int main() {
	cin.tie(0), cout.tie(0);
	ios_base::sync_with_stdio(0);
	int n, a;
	vector<int> v{ -1000000001 };
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a;
 		if (a > v.back())
			v.push_back(a);
		else
			*lower_bound(v.begin(), v.end(), a) = a;
	}
	cout << v.size() - 1;
	return 0;
}
