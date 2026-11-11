#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

void solve() {
    vector<i64> sp {-1};
    auto cmp = [&] (i64 x) {
        return lower_bound(sp.begin(), sp.end(), x) - sp.begin();
    };
    i64 n, q; cin >> n >> q;
    vector<i64> l (n), r (n), v (n);
    for (i64 i = 0; i < n; ++i) {
        cin >> l[i] >> r[i] >> v[i];
        sp.push_back(l[i]);
        sp.push_back(r[i]);
    }
    vector<array<i64, 2>> query (q);
    for (i64 i = 0; i < q; ++i) {
        cin >> query[i][0] >> query[i][1];
        sp.push_back(query[i][0]);
        sp.push_back(query[i][1]);
    }
    sort(sp.begin(), sp.end());
    sp.erase(unique(sp.begin(), sp.end()), sp.end());
    i64 m = sp.size();

    vector<i64> d (m);
    for (i64 i = 0; i < n; ++i) {
        i64 x = cmp(l[i]);
        i64 y = cmp(r[i]);
        d[x] += v[i];
        d[y] -= v[i];
    }
    partial_sum(d.begin(), d.end(), d.begin());
    vector<i64> p (m);
    for (i64 i = 1; i < m - 1; ++i) {
        p[i] = p[i - 1] + (sp[i + 1] - sp[i]) * d[i];
    }

    for (i64 i = 0; i < q; ++i) {
        cout << p[cmp(query[i][1]) - 1] - p[cmp(query[i][0]) - 1] << '\n';
    }
}

signed main()
{
    ios::sync_with_stdio(false); cin.tie(nullptr);
    solve();
    return 0;
}
