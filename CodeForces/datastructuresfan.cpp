#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

void solve() {
    int n; cin >> n;
    vector<int> r (n + 1);
    vector<int> a (n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        r[i + 1] = r[i] ^ a[i];
    }
    int xone = 0;
    for (int i = 0; i < n; ++i) {
        char t; cin >> t;
        if (t == '1') xone ^= a[i];
    }
    int q; cin >> q;
    for (int i = 0; i < q; ++i) {
        int x; cin >> x;
        if (x == 1){
            int f, g; cin >> f >> g;
            xone = xone ^ r[g] ^ r[f - 1];
        } else {
            int g; cin >> g;
            cout << (g ? xone : xone ^ r[n]) << ' ';
        }
    }
    cout << '\n';
}

signed main()
{
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int T; cin >> T;
    while(T--) solve();
    return 0;
}
