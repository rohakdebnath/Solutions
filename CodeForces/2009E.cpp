#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

void solve() {
    // terms are T_i = k * i + i * (i - 1) / 2, find 2 * T_i closest to T_n
    i64 n, k; cin >> n >> k;

    i64 T_n = k * n + n * (n - 1) / 2;
    i64 l = 1, r = n;
    i64 ans = INT64_MAX;  
    
    while (r - l > 1) {
        i64 m = l + (r - l) / 2;
        i64 T_m = k * m + m * (m - 1) / 2;
        
        if (2 * T_m <= T_n) {
            l = m;
        } else {
            r = m;
        }
    }

    for (i64 i = l; i <= r; ++i) {
        i64 T_i = k * i + i * (i - 1) / 2;
        i64 diff = abs(2 * T_i - T_n);
        ans = min(ans, diff);
    }

    cout << ans << '\n';
}

signed main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    i64 T; cin >> T;
    while (T--) solve();
    return 0;
}
