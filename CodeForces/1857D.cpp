#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

void solve() {
    int n; cin >> n;
    vector<int> a (n); for (int i = 0; i < n; ++i) cin >> a[i];
    vector<int> b (n); for (int i = 0; i < n; ++i) cin >> b[i];
    int m = -2e9;
    for (int i = 0; i < n; ++i) {
        m = max(a[i] - b[i], m);
    }
    vector<int> ans;
    for (int i = 0; i < n; ++i) {
        if (a[i] - b[i] == m) ans.push_back(i + 1);
    }
    int x = ans.size();
    cout << x << '\n';
    for (int i = 0; i < x; ++i) {
        cout << ans[i] << " \n"[i == x - 1];
    }
}

signed main()
{
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int T; cin >> T;
    while(T--) solve();
    return 0;
}
