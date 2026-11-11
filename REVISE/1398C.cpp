#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

void solve() {
    int n; cin >> n;
    vector<int> a (n); 
    for (int i = 0; i < n; ++i) {
        char c; cin >> c;
        a[i] = c - '0' - 1;
    }

    map<int, int> mp;
    mp[0] = 1;
    int s = 0;
    i64 ans = 0;
    for (int i = 0; i < n; ++i) {
        s += a[i];
        ans += mp[s];
        ++mp[s];
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
