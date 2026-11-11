#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

void solve() {
    int n; cin >> n;
    vector<int> a (n); for (int i = 0; i < n; ++i) cin >> a[i];
    sort(a.begin(), a.end());
    int ans = 1e9;
    int j = 0;
    for (int i = 0; i < n; ++i) {
        while (j < n and a[i] + a[i + 1] > a[j]) ++j;
        ans = min(ans, n - (j - i));
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
