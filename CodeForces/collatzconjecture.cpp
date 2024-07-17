#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

void solve() {
    int x, y, k; cin >> x >> y >> k;
    auto nex = [&] () -> int {
        return min(y - (x % y), k);
    };
    while (k and x >= y) {
        int t = nex();
        k -= t;
        x += t;
        while ((x % y) == 0) x /= y;
    }
    if (x < y) {
        x = (x + k - 1) % (y - 1) + 1;
    }
    cout << x << '\n';

}

signed main()
{
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int T; cin >> T;
    while(T--) solve();
    return 0;
}
