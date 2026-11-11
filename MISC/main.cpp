#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

void solve() {
    int n; cin >> n;
    vector<int> a (n), b (n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i] >> b[i];
    }

    vector<int> id (n); iota(id.begin(), id.end(), 0);
    sort(id.begin(), id.end(), [&] (int i, int j) {return a[i] + b[i] > a[j] + b[j];});
    i64 ans = -accumulate(b.begin(), b.end(), 0LL);
    for (int i = 0; i < n; i += 2) {
        ans += a[id[i]] + b[id[i]];
    }
    cout << ans << '\n';
}

signed main()
{
    ios::sync_with_stdio(false); cin.tie(nullptr);
    solve();
    return 0;
}
