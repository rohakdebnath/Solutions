#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

const i64 inf = 2e14;
void solve() {
    int n; cin >> n;
    vector<i64> a (n); for (int i = 0; i < n; ++i) cin >> a[i];
    vector<i64> p (n + 1); partial_sum(a.begin(), a.end(), p.begin() + 1);

    i64 ans = inf;
    int f = 1, t = 3;
    i64 L1 = 0, R1 = 0;
    for (int s = 2; s <= n - 2; ++s) {
        i64 L = p[s] - p[0], R = p[n] - p[s];
        while(f < s and L1 < L / 2) L1 += a[f++ - 1];
        while(t < n and R1 < R / 2) R1 += a[t++ - 1];
        for (int i = 0; i < 2; ++i) {
            for (int j = 0; j < 2; ++j) {
                i64 l1 = L1 - (i == 0 and f - 2 > 0 ? a[f - 2] : 0);
                i64 r1 = R1 - (j == 0 and t - 2 > s ? a[t - 2] : 0);
                i64 mx = max({l1, L - l1, r1, R - r1});
                i64 mn = min({l1, L - l1, r1, R - r1});
                ans = min(ans, mx - mn);
            }
        }
        R1 -= a[s];
    }
    cout << ans << '\n';
}

signed main()
{
    ios::sync_with_stdio(false); cin.tie(nullptr);
    solve();
    return 0;
}
