#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

const int mod = 998244353;
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
    int n, m; cin >> n >> m;
    vector<vector<int>> adj (n);
    for (int i = 0; i < m; ++i) {
        int a, b; cin >> a >> b;
        --a, --b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    vector<int> c (n, -1);
    vector<int> cc;
    auto dfs = [&] (auto&& self, int v, int col) -> bool{
        if (c[v] != -1) {
            if (c[v] != col) return false;
            return true;
        }
        bool bip = true;
        c[v] = col;
        cc.push_back(v);
        for (int u: adj[v]) {
            bip &= self(self, u, !col);
        }
        return bip;
    };
    mi ans = 1;
    for (int i = 0; i < n; ++i) {
        if (c[i] == -1) {
            bool bip = dfs(dfs, i, 0);
            vector<int> a = std::move(cc);
            array<int, 2> gs {};
            for (int x: a) {
                ++gs[c[x]];
            }
            ans *= bip * (pw(2, gs[0]) + pw(2, gs[1]));
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
