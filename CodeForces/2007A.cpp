#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

void solve() {
    int a, b; cin >> a >> b;
    if (a % 2 == 0) ++a;
    int ans = (b - a + 1) / 4;
    if ((b - a + 1) % 4 == 3 and (b & 1)) ++ans;
    cout << ans << '\n';
}

signed main()
{
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int T; cin >> T;
    while(T--) solve();
    return 0;
}
