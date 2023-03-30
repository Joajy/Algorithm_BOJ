#include<iostream>
#include<algorithm>
using namespace std;

struct Number {
	Number* child[10];	//0-9
	bool terminal = false;
};

Number* root;
bool check;
string number[10001];
int t, n;

void solution(string s) {
	Number* num = root;
	for (int i = 0; i < s.length(); i++) {
		if (num->terminal) {
			check = false;
			return;
		}
		int idx = s[i] - '0';
		if (num->child[idx] == nullptr) {
			Number* newN = new Number();
			num->child[idx] = newN;
		}
		num = num->child[idx];
	}
	num->terminal = true;
}

int main() {
	cin.tie(0), cout.tie(0);
	ios_base::sync_with_stdio(0);
	cin >> t;
	for (int i = 0; i < t; i++) {
		cin >> n;
		check = true;
		root = new Number();
		for (int j = 0; j < n; j++) cin >> number[j];
		sort(number, number + n);
		for (int j = 0; j < n; j++) 
			solution(number[j]);
		if (check) cout << "YES\n";
		else cout << "NO\n";
	}
	return 0;
}
