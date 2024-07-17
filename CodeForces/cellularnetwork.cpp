#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

#define UNSYNC ios::sync_with_stdio(false); cin.tie(nullptr);
#define sci(x) static_cast<int>(x)
#define all(x) x.begin(), x.end()
#define rep(i, ini, x) for (i64 i = ini; i < x; ++i)
#define per(i, fin, x) for (i64 i = fin; i >= x; --i)
#define VI vector<i64>
#define VVI vector<vector<i64>>

int main()
{
    UNSYNC
    i64 n, m; cin >> n >> m;
    VI a (n); rep(i, 0, n) cin >> a[i];
    VI b (m + 2); rep(i, 1, m + 1) cin >> b[i];
    b[0] = -4e9 - 1, b[m + 1] = 4e9 + 1;
    i64 ans = 0;
    i64 j = 1;
    rep(i, 0, n){
        while (a[i] >= b[j]) ++j;
        ans = max(ans, min(b[j] - a[i], a[i] - b[j - 1]));
    }
    cout << ans << '\n';
    return 0;
}
