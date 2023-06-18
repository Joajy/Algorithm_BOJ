 #include<iostream>
using namespace std;

int n;
int after[3], minDp[3]{ 0 }, maxDp[3]{ 0 };

int max(int a, int b) {
	if (a < b) return b;
	else return a;
}

int min(int a, int b) {
	if (a > b) return b;
	else return a;
}

void solution() {
	cin >> n;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < 3; ++j) {
			cin >> after[j];
		}
		int maxTmp[3], minTmp[3];
		//[0]
		maxTmp[0] = max(maxDp[0], maxDp[1]) + after[0];
		minTmp[0] = min(minDp[0], minDp[1]) + after[0];
		//[1]
		maxTmp[1] = max(max(maxDp[0], maxDp[1]), maxDp[2]) + after[1];
		minTmp[1] = min(min(minDp[0], minDp[1]), minDp[2]) + after[1];
		//[2]
		maxTmp[2] = max(maxDp[1], maxDp[2]) + after[2];
		minTmp[2] = min(minDp[1], minDp[2]) + after[2];
		for (int j = 0; j < 3; ++j) {
			maxDp[j] = maxTmp[j];
			minDp[j] = minTmp[j];
		}
	}
	int maxAns = max(max(maxDp[0], maxDp[1]), maxDp[2]);
	int minAns = min(min(minDp[0], minDp[1]), minDp[2]);
	cout << maxAns << ' ' << minAns;
}

int main() {
	cin.tie(0), cout.tie(0), ios_base::sync_with_stdio(0);
	solution();
	return 0;
}
