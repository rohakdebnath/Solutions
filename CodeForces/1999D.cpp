#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

void solve() {
    string s, t; cin >> s >> t;
    int n = t.size(), m = s.size();
    int i = 0, j = 0;
    while (i < n and j < m) {
        while (s[j] != t[i] and s[j] != '?' and j < m) ++j;
        if (j == m) {
            cout << "NO\n";
            return;
        }
        s[j] = t[i];
        ++i, ++j;
    }
    if (i != n) {
        cout << "NO\n";
        return;
    }
    for (; j < m; ++j) if (s[j] == '?') s[j] = 'a';
    cout << "YES\n" << s << '\n';
}

signed main()
{
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int T; cin >> T;
    while(T--) solve();
    return 0;
}
