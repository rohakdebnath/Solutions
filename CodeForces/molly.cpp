#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

struct custom_hash {
    static uint64_t splitmix64(uint64_t x) {
        // http://xorshift.di.unimi.it/splitmix64.c
        x += 0x9e3779b97f4a7c15;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
        return x ^ (x >> 31);
    }

    size_t operator()(uint64_t x) const {
        static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
        return splitmix64(x + FIXED_RANDOM);
    }
};
void solve() {
    int n, k; cin >> n >> k;
    vector<i64> a (n); for (int i = 0; i < n; ++i) cin >> a[i];
    partial_sum(a.begin(), a.end(), a.begin());
    vector<i64> p;
    i64 x = 1;
    if (abs(k) == 1) {
        p.push_back(k * x);
        p.push_back(x);
        p.erase(unique(p.begin(), p.end()), p.end());
    } else {
        while (abs(x) <= 1e14) {
            p.push_back(x);
            x *= k;
        }
    }
    i64 ans = 0;
    unordered_map<i64, int, custom_hash> f; f[0] = 1;
    for (int i = 0; i < n; ++i) {
        for (i64 j: p) {
            ans += f[a[i] - j];
        }
        ++f[a[i]];
    }
    cout << ans << '\n';
}

signed main()
{
    ios::sync_with_stdio(false); cin.tie(nullptr);
    solve();
    return 0;
}
