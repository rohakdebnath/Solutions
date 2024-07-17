#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

void solve() {
    int n, k; cin >> n >> k;
    vector<int> f (26);
    for (int i = 0; i < n; ++i) {
        char c; cin >> c;
        ++f[c - 'a'];
    }
    string ans = "";
    for (int i = 0; i < k; ++i) {
        int j = 0;
        while (j < n / k and f[j]) {
            --f[j++];
        }
        ans += 'a' + j;
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
