#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

void solve() {
    int n; cin >> n;
    vector<int> a (n); for (int i = 0; i < n; ++i) cin >> a[i];
    map<int, vector<int>> m;
    for (int i = 0; i < n; ++i) {
        m[a[i]].push_back(i);
    }
    map<int, int> ans;
    for (auto [u, v]: m) {
        int s = v.size();
        bool srv = 1;
        for (int i = 2; i < s; ++i) {
            if (v[i] - v[i - 1] != v[i - 1] - v[i - 2]) {
                srv = 0;
                break;
            }
        }
        if (srv) ans[u] = v.size() == 1 ? 0 : v[1] - v[0];
    }
    cout << ans.size() << '\n';
    for (auto [u, v]: ans) cout << u << ' ' << v << '\n';
}

signed main()
{
    ios::sync_with_stdio(false); cin.tie(nullptr);
    solve();
    return 0;
}
