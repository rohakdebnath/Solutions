#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

void solve() {
    int n; cin >> n;
    vector<array<int, 2>> v;
    for (int i = 0; i < n; ++i) {
        int l, r, a, b; cin >> l >> r >> a >> b;
        v.push_back({l, b});
    }
    sort(v.begin(), v.end());
    vector<array<int, 2>> a;
    for (auto [l, r]: v){
        if (!a.empty() and l <= a.back()[1]){
            a.back()[1] = max(a.back()[1], r);
        } else {
            a.push_back({l, r});
        }
    }
    int q; cin >> q;
    for (int i = 0; i < q; ++i) {
        int x; cin >> x;
        int t = upper_bound(a.begin(), a.end(), array{x, INT32_MAX}) - a.begin() - 1;
        if (t >= 0){
            x = max(x, a[t][1]);
        }
        cout << x << " \n"[i == q - 1];
    }
}

signed main()
{
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int T; cin >> T;
    while(T--) solve();
    return 0;
}
