#include<iostream>
using namespace std;

int n;
int dist[100][100];

void input() {
	cin >> n;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			cin >> dist[i][j];
		}
	}
}


void solution() {
	input();
	for (int m = 0; m < n; ++m) {
		for (int s = 0; s < n; ++s) {
			for (int e = 0; e < n; ++e) {
				if (dist[s][m] == 1 &&  dist[m][e] == 1) {
					dist[s][e] = 1;
				}
			}
		}
	}
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			cout << dist[i][j] << ' ';
		}cout << '\n';
	}
}

int main() {
	cin.tie(0), cout.tie(0), ios_base::sync_with_stdio(0);
	solution();
	return 0;
}
