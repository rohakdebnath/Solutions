#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

void chmax(int& a, int b) {
    a = max(a, b);
}
void solve() {
    int n; cin >> n;
    int m = 0;
    vector<int> f (n + 1);
    for (int i = 0; i < n; ++i) {
        int x; cin >> x;
        ++f[x];
        chmax(m, f[x]);
    }
    cout << n - m << '\n';
}

signed main()
{
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int T; cin >> T;
    while(T--) solve();
    return 0;
}
