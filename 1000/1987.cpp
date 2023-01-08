#include<iostream>
#include<algorithm>
using namespace std;

int dx[4] = { 0, 1, 0, -1 };
int dy[4] = { 1, 0, -1, 0 };
int answer, t, r, c;
string tour[21];
int alp[26];

void dfs(int x, int y, int count) {
    if (answer < count) 
        answer = count;
    for (int dir = 0; dir < 4; dir++) {
        int nx = x + dx[dir];
        int ny = y + dy[dir];
        if (nx < 0 || nx >= r || ny < 0 || ny >= c) continue;
        if (!alp[tour[nx][ny] - 'A']) {
            alp[tour[nx][ny] - 'A'] = 1;
            dfs(nx, ny, count + 1);
            alp[tour[nx][ny] - 'A'] = 0;
        }
    }
}

int main() {
    cin.tie(0); cout.tie(0);
    ios::sync_with_stdio(0);
    cin >> t;
    //each case starts at x = 1, y = 1 -> in program, (0,0)
    for (int z = 1; z <= t; z++) {
        cin >> r >> c;
        //initialize at each case
        answer = 0;
        fill(alp, alp + 26, 0);
        for (int i = 0; i < r; i++)
            cin >> tour[i];
        alp[tour[0][0] - 'A'] = 1;
        dfs(0, 0, 1);
        cout << '#' << z << ' ' << answer << '\n';
    }
    return 0;
}
