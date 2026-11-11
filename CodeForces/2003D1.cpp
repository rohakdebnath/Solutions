#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

void solve() {
    i64 n, m; cin >> n >> m;
    i64 secmex = 0;
    for (int i = 0; i < n; ++i) {
        int l; cin >> l;
        vector<int> a (l); for (int j = 0; j < l; ++j) cin >> a[j];
        sort(a.begin(), a.end());
        a.erase(unique(a.begin(), a.end()), a.end());
        l = a.size();
        i64 mex = 0;
        while (a[mex] == mex and mex < l) ++mex;
        mex++;
        if (mex <= l) {
            while (a[mex - 1] == mex and mex - 1 < l) ++mex;
        }
        secmex = max(secmex, mex);
    }
    if (m <= secmex) cout << secmex * (m + 1) << '\n';
    else cout << (m * (m + 1) / 2 - secmex * (secmex - 1) / 2 + secmex * secmex) << '\n';
}

signed main()
{
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int T; cin >> T;
    while(T--) solve();
    return 0;
}
