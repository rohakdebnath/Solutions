#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

void solve() {
    int n; cin >> n;
    string s, t; cin >> s >> t;
    int i = 0;
    while (i < n and s[i] == '0') ++i;
    for (; i < n; ++i) {
        s[i] = t[i];
    }
    cout << (s == t ? "YES\n": "NO\n");
}

signed main()
{
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int T; cin >> T;
    while(T--) solve();
    return 0;
}
