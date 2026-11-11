#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

void solve() {
    int n; cin >> n;
    vector<i64> a (n); for (i64 i = 0; i < n; ++i) cin >> a[i];
    vector<array<i64, 2>> p (n);
    for (i64 i = 0; i < n; ++i) {
        p[i][0] = a[i] + i;
        p[i][1] = i;
    }
    sort(p.begin(), p.end());
    map<i64, bool> vis;
    vis[n] = true;
    for (i64 i = 0; i < n; ++i) {
        if (vis.contains(p[i][0])) vis[p[i][0] + p[i][1]] = true;
    }
    cout << prev(vis.end()) -> first << '\n';
}

signed main()
{
    ios::sync_with_stdio(false); cin.tie(nullptr);
    i64 T; cin >> T;
    while(T--) solve();
    return 0;
}
