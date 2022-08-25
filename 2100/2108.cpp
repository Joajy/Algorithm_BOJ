#include<iostream>
#include<vector>
#include<algorithm>
#include<utility>
#include<cmath>
using namespace std;

pair<int, int> z[8002]{ {0, 0 } };

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	int n;
	double sum = 0;
	int a[3]{ 0 };
	cin >> n;
	vector<int> v;
	for (int i = 0; i < n; i++) {
		int t;
		cin >> t;
		sum += t;
		z[t + 4000].first++;
		z[t + 4000].second = t;
		v.push_back(t);
	}

	if (sum < 0) {
		if ((sum / n - int(sum / n)) > -0.5)
			sum /= n;
		else if (-int(sum) % n != 0)
			sum = sum / n - 1;
	}
	else {
		if (sum / n - int(sum / n) < 0.5)
			sum /= n;
		else
			sum = sum / n + 1;
	}

	sort(v.begin(), v.end());
	a[0] = v.at(n / 2);
	sort(z, z + 8001, greater<>());

	for (int i = 0; i < n; i++) {
		if (z[i].first != z[i + 1].first) {
			a[1] = z[i].second;
			break;
		}
		else {
			while (z[i].first == z[i + 1].first)
				i++;
			if (i == 0) a[1] = z[i].second;
			else if (z[i - 1].first > z[i].first) a[1] = z[i].second;
			else a[1] = z[i - 1].second;
			break;
		}
	}
	a[2] = v.back() - v.front();
	cout << (int)sum << '\n';
	for (int i = 0; i < 3; i++)
		cout << a[i] << '\n';

	return 0;
}
