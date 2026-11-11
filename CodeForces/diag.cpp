#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

void solve() {
    int n, k; cin >> n >> k;
    if (!k) {
        cout << "0\n";
        return;
    }
    vector<int> d (2 * n - 1);
    d[0] = n;
    for (int i = 1; i < 2 * n - 1; i += 2) {
        d[i] = d[i + 1] = d[i - 1] - 1;
    }
    partial_sum(d.begin(), d.end(), d.begin());
    cout << lower_bound(d.begin(), d.end(), k) - d.begin() + 1 << '\n';
}

signed main()
{
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int T; cin >> T;
    while(T--) solve();
    return 0;
}
