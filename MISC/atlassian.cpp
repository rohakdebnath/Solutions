#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

void chmin(i64& a, i64 b) {
    a = min(a, b);
}

const i64 inf = 1e18;
void solve() {
    int n; cin >> n;
    vector<int> a (n); for (int i = 0; i < n; ++i) cin >> a[i];
    int k; cin >> k;
    sort(a.begin(), a.end());
    vector<i64> p (n + 1); partial_sum(a.begin(), a.end(), p.begin() + 1);
    i64 ans = inf;
    for (int i = k; i <= n; ++i) {
        int x = i - k / 2 - 1;
        i64 t = (x - i + k + 1) * a[x] - (p[x + 1] - p[i - k]) + p[i] - p[x + 1] - (i - x - 1) * a[x];
        chmin(ans, t);
    }
    cout << ans << '\n';
}

signed main()
{
    ios::sync_with_stdio(false); cin.tie(nullptr);
    solve();
    return 0;
}
