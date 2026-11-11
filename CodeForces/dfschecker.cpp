#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

void solve() {
    int n, q; cin >> n >> q;
    vector<int> p (n, -1);
    for (int i = 1; i < n; ++i) {
        cin >> p[i];
        --p[i];
    }
    vector<int> a (n); for (int i = 0; i < n; ++i) cin >> a[i], --a[i];
    int v = 0; // 0 if for all the elements, the parent occurs at an index earlier than itself
    for (int i = 0; i < n; ++i) {
        v += (p[a[i]] >= a[i]);
    }

    while (q--) {
        int l, r; cin >> l >> r;
        --l, --r;
        v -= (p[a[l]] >= a[l]) + (p[a[r]] >= a[r]);
        v += (p[a[r]] >= a[l]) + (p[a[l]] >= a[r]);
        swap(a[r], a[l]);
        cout << (v == 0 ? "YES\n": "NO\n");
    }
}

signed main()
{
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int T; cin >> T;
    while(T--) solve();
    return 0;
}
// 0 1 5 3 2 4
// 0 1 4 3 2 5
