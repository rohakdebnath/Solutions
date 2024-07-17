#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

#define UNSYNC ios::sync_with_stdio(false); cin.tie(nullptr);
#define all(x) x.begin(), x.end()
#define rep(i, ini, x) for (int i = ini; i < x; ++i)
#define per(i, fin, x) for (int i = fin; i >= x; --i)

void solve() {
    int N, A, B; cin >> N >> A >> B;
    int e = max(min(B - A, N), 0);
    int ans = N * A + e * (e + 1) / 2;
    cout << ans << '\n';
}

signed main()
{
    UNSYNC
    int T;
    cin >> T;
    while(T--) solve();
    return 0;
}
