#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

void solve() {
    i64 n; cin >> n;
    string s; cin >> s;
    vector<i64> a (n); iota(a.begin(), a.end(), 1);
    vector<i64> p;
    for (i64 i = 0; i < n; ++i) {
        if (s[i] == '1') p.push_back(i);
    }
    i64 j = n - 1;
    for (i64 i = n - 1; i >= 0; --i) {
        if (s[i] == '1') continue;
        if (j > i) {
            a[j] = 0; --j;
            p.pop_back();
            while (j >= 0 and s[j] == '0') --j;
        }
    }
    i64 ans = accumulate(a.begin(), a.end(), 0LL);
    for (i64 i = (p.size() + 1) / 2; i < p.size(); ++i) ans -= a[p[i]];
    cout << ans << '\n';
}

signed main()
{
    ios::sync_with_stdio(false); cin.tie(nullptr);
    i64 T; cin >> T;
    while(T--) solve();
    return 0;
}
