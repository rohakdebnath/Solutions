#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

void solve() {
    int n; cin >> n;
    string s; cin >> s;
    vector<int> f (4);
    for (int i = 0; i < 4 * n; ++i) {
        if (s[i] == '?') continue;
        ++f[s[i] - 'A'];
    }
    int ans = 0;
    for (int i = 0; i < 4; ++i) {
        ans += min(n, f[i]);
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
