#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

void chmax(i64& a, i64 b) {
    a = max(a, b);
}

void solve() {
    i64 n, m; cin >> n >> m;
    vector<vector<i64>> meax (n, vector<i64> (2));
    i64 fmex = 0, smex = 0;
    for (int i = 0; i < n; ++i) {
        i64 l; cin >> l;
        vector<i64> a (l); for (i64 j = 0; j < l; ++j) cin >> a[j];
        sort(a.begin(), a.end());
        a.erase(unique(a.begin(), a.end()), a.end());
        l = a.size();
        i64 mex = 0;
        while (mex < l and a[mex] == mex) ++mex;
        meax[i][0] = mex;
        mex++;
        while (mex - 1 < l and a[mex - 1] == mex) ++mex;
        meax[i][1] = mex;
        chmax(fmex, meax[i][0]);
        chmax(smex, meax[i][1]);
    }
    vector<vector<i64>> adj (smex + 1);
    vector<i64> c (smex + 1);
    for (int i = 0; i < n; ++i) {
        ++c[meax[i][0]];
        adj[meax[i][0]].push_back(meax[i][1]);
    }
    vector<i64> dp (smex + 1);
    for (int i = smex; i >= 0; --i) {
        dp[i] = i;
        for (int u: adj[i]) chmax(dp[i], dp[u]);
        if (c[i] >= 2) {
            chmax(fmex, dp[i]);
        }
    }
    i64 ans = 0;
    for (int i = 0; i <= min(m, smex); ++i) {
        ans += max(dp[i], fmex);
    }
    if (m > smex) ans += (smex + m + 1) * (m - smex) / 2;
    cout << ans << '\n';
}

signed main()
{
    ios::sync_with_stdio(false); cin.tie(nullptr);
    i64 T; cin >> T;
    while(T--) solve();
    return 0;
}
