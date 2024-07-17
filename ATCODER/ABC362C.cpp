#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

void solve() {
    int n; cin >> n;
    vector<int> l (n), r (n);
    for (int i = 0; i < n; ++i) {
        cin >> l[i] >> r[i];
    }
    vector<int> ans = l;
    if (accumulate(l.begin(), l.end(), 0LL) > 0 or accumulate(r.begin(), r.end(), 0LL) < 0) {
        cout << "No\n";
        return;
    }
    cout << "Yes\n";
    i64 s = -accumulate(l.begin(), l.end(), 0LL);
    for (int i = 0; s > 0 and i < n; ++i) {
        ans[i] += min<i64>(r[i] - l[i], s);
        s -= min<i64>(r[i] - l[i], s);
    }
    for (int i = 0; i < n; ++i) {
        cout << ans[i] << " \n"[i == n - 1];
    }
}

signed main()
{
    ios::sync_with_stdio(false); cin.tie(nullptr);
    solve();
    return 0;
}
