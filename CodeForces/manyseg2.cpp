#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

void solve() {
    i64 n, m; cin >> n >> m;
    vector<array<i64, 2>> a (n);
    for (i64 i = 0; i < n; ++i) {
        cin >> a[i][0] >> a[i][1];
    }
    a.push_back({m + 1, m + 1});
    sort(a.begin(), a.end());

    for(i64 i = n - 1; i >= 0; --i){
        a[i][1] = min(a[i][1], a[i + 1][1]);
    }

    i64 ans = 0;
    i64 j = 0;
    for (i64 i = 1; i <= m; ++i) {
        while (j < n + 1 and a[j][0] < i) ++j;
        ans += a[j][1] - i;
    }
    cout << ans << '\n';
}

signed main()
{
    ios::sync_with_stdio(false); cin.tie(nullptr);
    solve();
    return 0;
}
