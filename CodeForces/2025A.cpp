#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

void solve() {
    string s, t; cin >> s >> t;
    int ans = s.size() + t.size();
    int x = 0;
    for (int i = 0; i < min(s.size(), t.size()); ++i) {
        if (s[i] == t[i]) ++x;
        else break;
    }
    ans = ans - max(x - 1, 0);
    cout << ans << '\n';
}

signed main()
{
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int T; cin >> T;
    while(T--) solve();
    return 0;
}
