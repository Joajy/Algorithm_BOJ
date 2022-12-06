#include<iostream>
#include<algorithm>
#include<set>
#define fast cin.tie(0), cout.tie(0), ios::sync_with_stdio(0);
using namespace std;

string answer[100001];
set<string> tmp;

int main() {
	fast;
	string s;
	int n, cnt = 0;
	cin >> n;
	for (int i = 0;i < n;i++) {
		int a = tmp.size();
		cin >> answer[cnt];
		s = answer[cnt];
		sort(s.begin(), s.end());
		tmp.insert(s);
		int b = tmp.size();
		if (a != b) 
			cnt++;
	}
	for (int i = 0;i < cnt;i++)
		cout << answer[i] << '\n';
	return 0;
}
