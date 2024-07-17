#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

void solve() {
    int n, k; cin >> n >> k;
    vector<int> s;
    vector<vector<int>> u (n, vector<int> (3));
    for (int i = 0; i < n; ++i) {
        int l, r, v; cin >> l >> r >> v;
        s.push_back(l);
        s.push_back(r + 1);
        u[i] = {l, r + 1, v};
    }
    auto cmp = [&] (int x) {
        return lower_bound(s.begin(), s.end(), x) - s.begin();
    };
    sort(s.begin(), s.end());
    s.erase(unique(s.begin(), s.end()), s.end());

    int m = s.size();
    vector<int> a (m);
    for (int i = 0; i < n; ++i) {
        auto x = u[i];
        a[cmp(x[0])] += x[2];
        a[cmp(x[1])] -= x[2];
    }
    partial_sum(a.begin(), a.end(), a.begin());

    map<int, int> dp;
    map<int, int> prev;
    for (int i = 0; i < m; ++i) {
        if (a[i] - k >= 0 and dp[a[i] - k] >= 1) {
            dp[a[i]] = dp[a[i] - k] + 1;
            prev[a[i]] = a[i] - k;
        } else {
            dp[a[i]] = 1;
            prev[a[i]] = -1;
        }
    }

    int ans = 0, e = 0;
    for (auto[u, v]: dp) {
        if (v > ans) {
            ans = v;
            e = u;
        }
    }
    cout << ans << '\n';
    vector<int> z;
    while (e != -1) {
        z.push_back(e);
        e = prev[e];
    }
    reverse(z.begin(), z.end());
    for (int i = 0; i < ans; ++i) {
        cout << z[i] << " \n"[i == ans - 1];
    }
}

signed main()
{
    ios::sync_with_stdio(false); cin.tie(nullptr);
    solve();
    return 0;
}
