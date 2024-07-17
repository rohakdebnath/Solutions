#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

void solve() {
    i64 n; cin >> n;
    vector<i64> ans;
    ans.push_back(n);
    for (i64 i = 0; i <= 62; ++i) {
        if (n & (1LL << i) and (n ^ (1LL << i)) > 0) ans.push_back(n ^ (1LL << i));
    }
    cout << ans.size() << '\n';
    for (int i = ans.size() - 1; i >= 0; --i) {
        cout << ans[i] << " \n"[i == 0];
    }
}

signed main()
{
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int T; cin >> T;
    while(T--) solve();
    return 0;
}
