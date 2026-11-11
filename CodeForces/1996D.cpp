#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

void solve() {
    int n, x; cin >> n >> x;
    i64 ans = 0;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; i * j <= n and i + j <= x; ++j) {
            ans += min(x - i - j, (n - i * j) / (i + j));
        }
    }
    cout << ans << '\n';
}

signed main()
{
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int T; cin >> T;
    while(T--) solve();
    return 0;
}
