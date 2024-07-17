#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

const int inf = 1e9;
void solve() {
    int n; cin >> n;
    vector<int> a (n * (n - 1) / 2); for (int i = 0; i < n * (n - 1) / 2; ++i) cin >> a[i];
    sort(a.begin(), a.end());
    int s = 0, d = n - 1;
    while (d) {
        s += d;
        d--;
        cout << a[s - 1] << ' ';
    }
    cout << inf << '\n';
}

signed main()
{
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int T; cin >> T;
    while(T--) solve();
    return 0;
}
