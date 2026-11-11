#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

mt19937 rng((i64) std::chrono::steady_clock::now().time_since_epoch().count());
i64 rnd(i64 x, i64 y) {
    return uniform_int_distribution<i64>(x, y)(rng);
}

void solve() {
    i64 n, q; cin >> n >> q;
    vector<i64> a (n);
    map<int, i64> hash;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        if (hash.find(a[i]) == hash.end()) {
            hash[a[i]] = rnd(1, 1LL << 60);
        }
    }
    vector<i64> rxor (n + 1);
    for (i64 i = 1; i <= n; ++i) {
        rxor[i] = rxor[i - 1] ^ hash[a[i - 1]];
    }
    while (q--) {
        i64 l, r; cin >> l >> r;
        cout << ((rxor[r] ^ rxor[l - 1]) == 0 ? "YES\n": "NO\n");
    }
}

signed main()
{
    ios::sync_with_stdio(false); cin.tie(nullptr);
    i64 T; cin >> T;
    while(T--) solve();
    return 0;
}
