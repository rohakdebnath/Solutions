#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

#define UNSYNC ios::sync_with_stdio(false); cin.tie(nullptr);
#define sci(x) static_cast<i64>(x)
#define all(x) x.begin(), x.end()
#define rep(i, ini, x) for (i64 i {ini}; i < x; ++i)
#define per(i, fin, x) for (i64 i {fin}; i >= x; --i)
#define VI vector<i64>
#define VVI vector<vector<i64>>

int main()
{
    UNSYNC
    i64 N, Q; cin >> N >> Q;
    VI a (N); rep(i, 0, N) cin >> a[i];
    VI cuma (N + 1); cuma[0] = 0;
    rep(i, 1, N + 1) cuma[i] = cuma[i - 1] + a[i - 1];
    rep(i, 0, Q)
    {
        i64 l, r; cin >> l >> r;
        cout << cuma[r] - cuma[l] << '\n';
    }
    return 0;
}
