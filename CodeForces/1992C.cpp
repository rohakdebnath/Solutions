#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

void solve() {
    int n, m, k; cin >> n >> m >> k;
    vector<int> a (m); iota(a.begin(), a.end(), 1);
    reverse(a.begin(), a.end());
    a.resize(n); iota(a.begin() + m, a.end(), m + 1);
    reverse(a.begin(), a.end());
    for (int i = 0; i < n; ++i) {
        cout << a[i] << " \n"[i == n - 1];
    }
}

signed main()
{
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int T; cin >> T;
    while(T--) solve();
    return 0;
}
