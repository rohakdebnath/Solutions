#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

const int inf = 1e9;
void solve() {
    int n; cin >> n;
    vector<int> a (n); for (int i = 0; i < n; ++i) cin >> a[i];
    int l = inf, w = inf;
    int ans = 0; //bob will win if after alice places the chip, i) he can move the chip to a position where alice loses (a smaller element where alice loses) or ii) bob has no moves (no smaller elements)
    for (int i = 0; i < n; ++i) {
        if (w < a[i] or (l >= a[i] and w >= a[i])) { //bob wc
            l = min(l, a[i]);
        } else {
            w = min(w, a[i]);
            ++ans;
        }
    }
    cout << ans << '\n';
}

signed main()
{
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int T; cin >> T;
    while(T--) solve();
    return 0;
}
