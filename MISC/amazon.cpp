#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

void solve() {
    int n; cin >> n;
    vector<int> a (n); for (int i = 0; i < n; ++i) cin >> a[i];
    map<int, int> firstocc;
    vector<int> pmin (n); pmin[0] = a[0];
    for (int i = 0; i < n; ++i) {
        if (i > 0) pmin[i] = min(pmin[i - 1], a[i]);
        if (firstocc.find(a[i]) == firstocc.end()) firstocc[a[i]] = i;
    }
    sort(pmin.begin(), pmin.end());
    pmin.erase(unique(pmin.begin(), pmin.end()), pmin.end());
    
    int ans = 0, j = 0;
    for (int i = n - 1; i >= 0; --i) {
        if (a[i] == pmin[j]) ++ans;
        if (i == firstocc[pmin[j]]) ++j;
    }
    cout << ans << '\n';
}

signed main()
{
    ios::sync_with_stdio(false); cin.tie(nullptr);
    solve();
    return 0;
}
