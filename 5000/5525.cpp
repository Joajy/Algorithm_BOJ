#include <iostream>
using namespace std;

int n, m;
string s;

void input() {
	cin >> n >> m >> s;
}

void solution() {
	input();
	int answer = 0;
	for (int i = 0; i < s.length(); ++i) {
		if (s[i] == 'O') continue;
		int len = 0;
		while (s[i + 1] == 'O' && s[i + 2] == 'I') {
			++len;
			if (len == n) {
				++answer;
				--len;
			}
			i += 2;
		}
	}
	cout << answer;
}

int main(){
    cin.tie(0), cout.tie(0);
    ios_base::sync_with_stdio(0);
    solution();
    return 0;
}
