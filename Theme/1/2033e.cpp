#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

void solve() {
    int n; cin >> n;
    vector<int> p (n); for (int i = 0; i < n; ++i) cin >> p[i], --p[i];

    vector<int> vis (n);
    int ans = 0;
    for (int i = 0; i < n; ++i) {
        if (!vis[i]) {
            int l = 0, c = i;
            while (!vis[c]) {
                vis[c] = 1;
                c = p[c];
                ++l;
            }
            ans += (l - 1) / 2;
        }
    }
    cout << ans << '\n';
}

signed main()
{
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int T; cin >> T;
    while(T--) solve();
    return 0;
}
