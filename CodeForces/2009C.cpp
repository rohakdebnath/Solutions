#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

void solve() {
    i64 x, y, k; cin >> x >> y >> k;
    i64 ans = 2 * max((x + k - 1) / k, (y + k - 1) / k) - ((x + k - 1) / k > (y + k - 1) / k);
    cout << ans << '\n';

}

signed main()
{
    ios::sync_with_stdio(false); cin.tie(nullptr);
    i64 T; cin >> T;
    while(T--) solve();
    return 0;
}
