#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

void solve() {
    int n, k; cin >> n >> k;
    vector<int> a (k); for (int i = 0; i < k; ++i) cin >> a[i];
    sort(a.begin(), a.end());
    int s = 2 * accumulate(a.begin(), a.end() - 1, 0LL) - (k - 1);
    cout << s << '\n';
}

signed main()
{
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int T; cin >> T;
    while(T--) solve();
    return 0;
}
