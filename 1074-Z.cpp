#include <iostream>
using namespace std;

int n, r, c, ans;

void Z(int y, int x, int size)
{
    if (y == r && x == c) {
        cout << ans;
        return;
    }
    // if r, c is in current of four Quadrant
    if (r < y + size && r >= y && c < x + size && c >= x) {
        // First Quadrant
        Z(y, x, size / 2);
        // Second Quadrant
        Z(y, x + size / 2, size / 2);
        // Third Quadrant
        Z(y + size / 2, x, size / 2);
        // Fourth Quadrant
        Z(y + size / 2, x + size / 2, size / 2);
    }
    else
        ans += size * size;
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> r >> c;

    // bit extension idea
    Z(0, 0, 1 << n);

    return 0;
}
