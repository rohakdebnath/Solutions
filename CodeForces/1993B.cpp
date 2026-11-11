#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

void solve() {
    i64 n; cin >> n;
    vector<i64> a (n); for (i64 i = 0; i < n; ++i) cin >> a[i];
    vector<i64> e;
    i64 mo = 0;
    for (int i = 0; i < n; ++i) {
        if (a[i] % 2 == 0){
            e.push_back(a[i]);
        } else {
            mo = max(mo, a[i]);
        }
    }
    sort(e.begin(), e.end());
    if (e.size() == n){
        cout << "0\n";
        return;
    }
    int ans = 0;
    for (int i: e) {
        if (mo < i) {
            ans += 2;
            mo += 2 * i;
        } else {
            ++ans;
            mo += i;
        }
    }
    cout << ans << '\n';
}

signed main()
{
    ios::sync_with_stdio(false); cin.tie(nullptr);
    i64 T; cin >> T;
    while(T--) solve();
    return 0;
}
