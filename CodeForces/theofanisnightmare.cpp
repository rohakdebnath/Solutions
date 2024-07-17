#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

#define UNSYNC ios::sync_with_stdio(false); cin.tie(nullptr);
#define sci(x) static_cast<i64>(x)
#define all(x) x.begin(), x.end()
#define rep(i, ini, x) for (i64 i = ini; i < x; ++i)
#define per(i, fin, x) for (i64 i = fin; i >= x; --i)
#define VI vector<i64>
#define VVI vector<vector<i64>>

void solve()
{
    i64 n; cin >> n;
    VI a (n); rep(i, 0, n) cin >> a[i];
    VI prefs (n); prefs[n - 1] = a[n - 1];
    per(i, n - 2, 0) prefs[i] = prefs[i + 1] + a[i];
    i64 ans = prefs[0];
    per(i, n - 1, 1) ans += max(0LL, prefs[i]);
    cout << ans << '\n';
}

int main()
{
    UNSYNC
    i64 T;
    cin >> T;
    while(T--) solve();
    return 0;
}
