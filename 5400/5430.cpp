#include<iostream>
#include<utility>
using namespace std;

string ar[100002];

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int t;
	cin >> t;
	while (t--) {
		bool Switch = false, err = false;
		string x;
		int n, cnt = 0;
		cin >> x >> n;
		for (int i = 0; i < n; i++)
			ar[i] = "";
		string arr;
		cin >> arr;
		for (int i = 1; i < arr.length() - 1; i++) {
			if (arr[i] == ',')
				cnt++;
			else
				ar[cnt] += arr[i];
		}
		int start = 0, end = n - 1;

		for (auto i : x) {
			if (i == 'R')
				Switch = !Switch;
			else if (i == 'D') {
				if (start > end) {
					err = true;
					break;
				}
				if (Switch == false)
					start++;
				else
					end--;
			}
		}
		if (err) {
			cout << "error\n";
			continue;
		}
		cout << '[';
		if (Switch == true) {
			for (end; end >= start; end--) {
				if (start != end)
					cout << ar[end] << ',';
				else
					cout << ar[end];
			}
		}
		else {
			for (start; start <= end; start++) {
				if (start != end)
					cout << ar[start] << ',';
				else
					cout << ar[start];
			}
		}
		cout << "]\n";
	}
	return 0;
}
