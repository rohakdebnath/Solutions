#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

void solve() {
    int n; cin >> n;
    vector<int> a (n), b (n);
    map<int, int> f;
    map<int, int> vis;
    for (int i = 0; i < n; ++i) {
        cin >> a[i] >> b[i];
        ++f[a[i]];
        if (a[i] == b[i]) {
            if (vis[a[i]]) f[a[i]] = 0;
            vis[a[i]] = 1;
        }
    }
    for (int i = 0; i < n; ++i) {
        if (a[i] == b[i]) {
            f[b[i]] = min(f[b[i]], 1);
        }
        else f[b[i]] = 0;
    }
    int ans = 0;
    for (auto [u, v]: f) ans += v;
    cout << ans << '\n';
}

signed main()
{
    ios::sync_with_stdio(false); cin.tie(nullptr);
    solve();
    return 0;
}
