#include<iostream>
#include<string>
#define fast cin.tie(0), cout.tie(0), ios::sync_with_stdio(0);
using namespace std;

int main() {
	fast;
	string x, num;
	cin >> x;
	bool minus = false;
	int answer = 0;
	//a - b + c -> a - (b + c)
	for (int i = 0;i <= x.length();i++) {
		if (x[i] == '+' || x[i] == '-' || x.length() == i) {
			if (minus)
				answer -= stoi(num);
			else
				answer += stoi(num);
			num.clear();
		}
		else
			num += x[i];
		if (x[i] == '-')
			minus = true;
	}
	cout << answer;
	return 0;
}
