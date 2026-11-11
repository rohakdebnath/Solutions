#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

const int mod = 1e9 + 7;
const int maxn = 1e7;

struct mi {
    int v;
    explicit operator int() const { return v; }
    mi() { v = 0; }
    mi(long long x) : v(x % mod) { v += (v < 0) * mod; }
};

mi& operator+=(mi& a, mi b) {
    if ((a.v += b.v) >= mod) a.v -= mod;
    return a;
}

mi& operator-=(mi& a, mi b) {
    if ((a.v -= b.v) < 0) a.v += mod;
    return a;
}

mi operator+(mi a, mi b) { return a += b; }
mi operator-(mi a, mi b) { return a -= b; }
mi operator*(mi a, mi b) { return mi((long long)a.v * b.v); }
mi& operator*=(mi& a, mi b) { return a = a * b; }

mi pw(mi a, long long p) {
    mi res = 1;
    while (p > 0) {
        if (p & 1) res *= a;
        a *= a;
        p >>= 1;
    }
    return res;
}

mi inv(mi a) {
    return pw(a, mod - 2);
}
mi operator/(mi a, mi b) { return a * inv(b); }

vector<mi> fct(maxn + 1, 1);

void prefact() {
    for (int i = 2; i <= maxn; ++i)
        fct[i] = fct[i - 1] * i;
}

mi ncr(int n, int r) {
    if (r < 0 or r > n) return 0;
    return fct[n] * inv(fct[r] * fct[n - r]);
}

void solve() {
    int n; cin >> n;
    vector<int> a (n); for (int i = 0; i < n; ++i) cin >> a[i];
    vector<int> p (n); for (int i = 0; i < n; ++i) cin >> p[i];
    mi d = inv(10000);

    mi ans = 0;
    for (int i = 0; i < 10; ++i) {
        for (int j = i; j < 10; ++j) {
            array<array<mi, 2>, 2> dp = {};
            dp[0][0] = 1;
            for (int k = 0; k < n; ++k) {
                array<array<mi, 2>, 2> ndp = {};
                for (int x = 0; x < 2; ++x) {
                    for (int y = 0; y < 2; ++y) {
                        ndp[x ^ (a[k] >> i & 1)][y ^ (a[k] >> j & 1)] += dp[x][y] * p[k] * d;
                        ndp[x][y] += dp[x][y] * (1 - p[k] * d);
                    }
                }
                dp = std::move(ndp);
            }
            ans += (1 << (i + j)) * dp[1][1] * (1 + (i != j));
        }
    }

    cout << int(ans) << '\n';
}

signed main()
{
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int T; cin >> T;
    while(T--) solve();
    return 0;
}
// #include <bits/stdc++.h>

// using namespace std;
// using i64 = long long;

// const int mod = 1e9 + 7;
// const int maxn = 1e7;

// struct mi {
//     int v;
//     explicit operator int() const { return v; }
//     mi() { v = 0; }
//     mi(long long x) : v(x % mod) { v += (v < 0) * mod; }
// };

// mi& operator+=(mi& a, mi b) {
//     if ((a.v += b.v) >= mod) a.v -= mod;
//     return a;
// }

// mi& operator-=(mi& a, mi b) {
//     if ((a.v -= b.v) < 0) a.v += mod;
//     return a;
// }

// mi operator+(mi a, mi b) { return a += b; }
// mi operator-(mi a, mi b) { return a -= b; }
// mi operator*(mi a, mi b) { return mi((long long)a.v * b.v); }
// mi& operator*=(mi& a, mi b) { return a = a * b; }

// mi pw(mi a, long long p) {
//     mi res = 1;
//     while (p > 0) {
//         if (p & 1) res *= a;
//         a *= a;
//         p >>= 1;
//     }
//     return res;
// }

// mi inv(mi a) {
//     return pw(a, mod - 2);
// }
// mi operator/(mi a, mi b) { return a * inv(b); }

// vector<mi> fct(maxn + 1, 1);

// void prefact() {
//     for (int i = 2; i <= maxn; ++i)
//         fct[i] = fct[i - 1] * i;
// }

// mi ncr(int n, int r) {
//     if (r < 0 or r > n) return 0;
//     return fct[n] * inv(fct[r] * fct[n - r]);
// }

// void solve() {
//     int n; cin >> n;
//     vector<int> a (n); for (int i = 0; i < n; ++i) cin >> a[i];
//     vector<int> p (n); for (int i = 0; i < n; ++i) cin >> p[i];
//     mi d = inv(10000);

//     mi ans = 0;
//     for (int i = 0; i < 10; ++i) {
//         vector<mi> dp (2); //dp[k][i][j] = probablity of ith bit on/off (-> j) by the end of processing the kth element
//         dp[0] = 1;
//         for (int j = 0; j < n; ++j) {
//             vector<mi> ndp (2);
//             for (int k = 0; k < 2; ++k) {
//                 ndp[k ^ (a[j] >> i & 1)] += dp[k] * p[j] * d;
//                 ndp[k] += dp[k] * (1 - p[j] * d);
//             }
//             dp = std::move(ndp);
//         }
//         ans += (1 << i) * dp[1];
//     }

//     cout << int(ans) << '\n';
// }

// signed main()
// {
//     ios::sync_with_stdio(false); cin.tie(nullptr);
//     int T; cin >> T;
//     while(T--) solve();
//     return 0;
// }




