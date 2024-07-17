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
    VI b (n); rep(i, 0, n) cin >> b[i];
    VI maxl (n); maxl[0] = b[0] + 0;
    rep(i, 1, n) maxl[i] = max(maxl[i - 1], b[i] + i);
    VI maxr (n); maxr[n - 1] = b[n - 1] - (n - 1);
    per(i, n - 2, 0) maxr[i] = max(maxr[i + 1], b[i] - i);

    i64 ans = 0;
    rep(i, 1, n - 1) ans = max(ans, b[i] + maxl[i - 1] + maxr[i + 1]);
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
