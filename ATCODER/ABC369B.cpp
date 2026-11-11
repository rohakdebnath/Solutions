#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

void solve() {
    int n; cin >> n;
    vector<int> l, r;
    for (int i = 0; i < n; ++i) {
        int x; cin >> x;
        char c ; cin >> c;
        if (c == 'L') l.push_back(x);
        else r.push_back(x);
    }
    int ans = 0;
    if (l.size() > 1) {
        for (int i = 1; i < l.size(); ++i) {
            ans += abs(l[i] - l[i - 1]);
        }
    }
    if (r.size() > 1) {
        for (int i = 1; i < r.size(); ++i) {
            ans += abs(r[i] - r[i - 1]);
        }
    }
    cout << ans << '\n';
}

signed main()
{
    ios::sync_with_stdio(false); cin.tie(nullptr);
    solve();
    return 0;
}
