#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

vector<int> zfunc(const string& s) {
    int n = s.size();
    vector<int> z(n);
    for (int i = 1, l = 0, r = 0; i < n; ++i) {
        if (i < r) z[i] = min(r - i, z[i - l]);
        while (i + z[i] < n and s[z[i]] == s[i + z[i]]) ++z[i];
        if (i + z[i] > r) l = i, r = i + z[i];
    }
    return z;
}

void solve() {
    int n, m; cin >> n >> m;
    string s, t; cin >> s >> t;
    auto p = zfunc(t + "#" + s);
    auto q = zfunc(string(t.rbegin(), t.rend()) + "#" + string(s.rbegin(), s.rend()));
    int ans = 0;
    for (int i = 0; i + m <= n; ++i) {
        int k = p[m + 1 + i];
        if (k == m) ++ans;
        else if (k + 1 < m and s[i + k] == t[k + 1] and s[i + k + 1] == t[k]
                 and q[n + 1 - i] >= m - k - 2) ++ans;
    }
    cout << ans << '\n';
}

signed main()
{
    ios::sync_with_stdio(false); cin.tie(nullptr);
    solve();
    return 0;
}
