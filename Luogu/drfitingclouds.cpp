#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

void solve() {
    i64 n, m; cin >> n >> m;
    vector<i64> l (n), r (n), sp {0};
    vector<vector<i64>> w (2, vector<i64> (n)); //w[i][j] = duration when exactly i + 1 roses are active in the lifetime of rose j

    for (i64 i = 0; i < n; ++i) {
        cin >> l[i];
        r[i] = l[i] + m;
        sp.push_back(l[i]);
        sp.push_back(r[i]);
    }
    sort(sp.begin(), sp.end());
    sp.erase(unique(sp.begin(), sp.end()), sp.end());
    i64 k = sp.size();

    auto cmp = [&] (i64 x) {
        return lower_bound(sp.begin(), sp.end(), x) - sp.begin();
    };

    vector<vector<int>> start (k), end (k); //start[i] = index of all the segments which start at cmp index of i
    for (i64 i = 0; i < n; ++i) {
        i64 x = cmp(l[i]), y = cmp(r[i]);
        start[x].push_back(i);
        end[y].push_back(i);
    }

    i64 sum = 0;
    set<i64> active;
    for (i64 i = 1; i < k; ++i) {
        for (i64 id: start[i]) active.insert(id);
        for (i64 id: end[i]) active.erase(active.find(id));

        if (active.size() == 1) {
            w[0][*active.begin()] += sp[i + 1] - sp[i];
            sum += sp[i + 1] - sp[i];
        }
        if (active.size() == 2) {
            w[1][*active.begin()] += sp[i + 1] - sp[i];
            w[1][*(++active.begin())] += sp[i + 1] - sp[i];
        }
    }

    i64 ans = 0;
    for (i64 i = 0; i < n; i++) {
        ans = max(ans, sum - w[0][i] + w[1][i] + m);
    }
    cout << ans << '\n';
}

signed main()
{
    ios::sync_with_stdio(false); cin.tie(nullptr);
    solve();
    return 0;
}
