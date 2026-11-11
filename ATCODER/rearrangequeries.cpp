#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

mt19937 rng((i64) std::chrono::steady_clock::now().time_since_epoch().count());
i64 rnd(i64 x, i64 y) {
    return uniform_int_distribution<i64>(x, y)(rng);
}

const i64 mod = (1LL << 62) - 1;
const i64 lim = (1LL << 61) - 1;
void solve() {
    i64 n, q; cin >> n >> q;
    vector<i64> hash (n + 1);
    for (int i = 0; i < n; ++i) {
        hash[i + 1] = rnd(1, lim);
    }
    
    vector<i64> ha (n + 1), hb (n + 1);
    for (int i = 0; i < n; ++i) {
        i64 x; cin >> x;
        ha[i + 1] = (ha[i] + hash[x]) % mod;
    }
    for (int i = 0; i < n; ++i) {
        i64 x; cin >> x;
        hb[i + 1] = (hb[i] + hash[x]) % mod;
    }
    for (int i = 0; i < q; ++i) {
        int l, r, L, R; cin >> l >> r >> L >> R;
        --l, --L;
        cout << ((ha[r] - ha[l] + mod) % mod == (hb[R] - hb[L] + mod) % mod ? "Yes\n": "No\n");
    }

}

signed main()
{
    ios::sync_with_stdio(false); cin.tie(nullptr);
    solve();
    return 0;
}
