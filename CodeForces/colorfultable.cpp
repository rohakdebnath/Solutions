#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

void solve() {
    int n, k; cin >> n >> k;
    vector<int> a (n); for (int i = 0; i < n; ++i) cin >> a[i];
    vector<int> id (n); iota(id.begin(), id.end(), 0);
    sort(id.begin(), id.end(), [&] (int i, int j) {return a[i] < a[j];});
    vector<int> ans (k + 1);
    vector<int> smax (n), smin (n);
    for (int i = n - 1; i >= 0; --i) {
        smax[i] = (i == n - 1 ? id[n - 1] : max(smax[i + 1], id[i]));
        smin[i] = (i == n - 1 ? id[n - 1] : min(smin[i + 1], id[i]));
    }
    for (int i = 0; i < n; ++i) {
        int d = smax[i] - smin[i] + 1;
        ans[a[id[i]]] = max(ans[a[id[i]]], 2 * d);
    }
    for (int i = 0; i < k; ++i) {
        cout << ans[i + 1] << " \n"[i == k - 1];
    }
}

signed main()
{
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int T; cin >> T;
    while(T--) solve();
    return 0;
}
