#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

void solve() {
    int n,k, x; cin >> n >> k >> x;
    vector<int> a (n); for (int i = 0; i < n; ++i) cin >> a[i];
    a.insert(a.begin() + k, x);
    for (int i = 0; i <= n; ++i) {
        cout << a[i] << " \n"[i == n];
    }
}

signed main()
{
    ios::sync_with_stdio(false); cin.tie(nullptr);
    solve();
    return 0;
}
