#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

void solve() {
    int l, r; cin >> l >> r;
    int L, R; cin >> L >> R;
    int s = max(l, L), e = min(r, R);
    cout << (e >= s ? e - s + ((e + 1 <= R and e + 1 >= L) or (e + 1 <= r and e + 1 >= l)) + ((s - 1 <= R and s - 1 >= L) or (s - 1 <= r and s - 1 >= l)) : 1) << '\n';
}

signed main()
{
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int T; cin >> T;
    while(T--) solve();
    return 0;
}
