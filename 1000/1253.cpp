#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

int n;
vector<int> a;

void input() {
	cin >> n;
	int num;
	for (int i = 0; i < n; ++i) {
		cin >> num;
		a.push_back(num);
	}
	sort(a.begin(), a.end());
}

void solution() {
	input();
	if (n < 3) {
		cout << 0;
		return;
	}
	int answer = 0;
	for (int i = 0; i < n; ++i) {
		int st = 0, en = n - 1;
		while (st < en) {            
			if (st == i) {
				++st; continue;
			}
			if (en == i) {
				--en; continue;
			}
			int sum = a[st] + a[en];
			if (sum == a[i] && st != i && en != i) {
				++answer;
				break;
			}
			if (sum < a[i]) {
				++st;
			}
			else {
				--en;
			}
		}
	}
	cout << answer;
}

int main() {
	cin.tie(0), cout.tie(0);
	ios_base::sync_with_stdio(0);
 	solution();
	return 0;
} 
