#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

void solve() {
    int n; cin >> n;
    int ans = 0;
    auto check = [&] (vector<int>& v) {
        int m = 0, t = 0;
        for (int i = 0; i < n; ++i) {
            m = max(m, (i + 1) * v[i]);
            t += (i + 1) * v[i];
        }
        return t - m;
    };
    for (int i = 0; i < n; ++i) {
        vector<int> p (n); iota(p.begin(), p.end(), 1);
        reverse(p.begin() + i, p.end());
        ans = max(ans, check(p));
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
