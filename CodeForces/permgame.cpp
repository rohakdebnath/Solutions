#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

void solve() {
    int n; cin >> n;
    vector<int> a (n); for (int i = 0; i < n; ++i) cin >> a[i];
    vector<int> m (n + 1);
    int ef = 0, c = 0, es = 0;

    for (int i = 0; i < n; ++i) {
        if (a[i] != i + 1) {
            ++ef;
            m[a[i]] = 1;
        }
    }
    for (int i = 0; i < n; ++i) {
        if (a[i] != n - i) {
            if (m[a[i]]) {
                --ef;
                ++c;
            } else {
                ++es;
            }
        }
    }
    if (ef > c + es) cout << "Second\n";
    else if (es >= c + ef) cout << "First\n";
    else cout << "Tie\n";
}

signed main()
{
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int T; cin >> T;
    while(T--) solve();
    return 0;
}
