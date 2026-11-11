#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

int interact(int l, int r) {
    cout << "? " << l << ' ' << r << endl;
    int x; cin >> x;
    return x;
}
void solve() {
    int l = 1, r = 999;
    while (r - l > 1) {
        int x = l + (r - l) / 3;
        int y = l + 2 * (r - l) / 3;
        int q = interact(x, y);
        if (q == x * y) l = y;
        else if (q == x * (y + 1)) l = x, r = y;
        else r = x;
    }
    cout << "! " << r << '\n';
}

signed main()
{
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int T; cin >> T;
    while(T--) solve();
    return 0;
}

