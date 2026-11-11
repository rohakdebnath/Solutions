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
    vector<vector<int>> adj (n);
    for (int i = 0; i < n - 1; ++i) {
        int a, b; cin >> a >> b;
        --a, --b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    vector<int> m (n); 
    mi ans = 0;
    auto dfs = [&] (auto&& self, int v, int p) -> void{
        m[v] = 1;
        for (int u: adj[v]) {
            if (u == p) continue;
            self(self, u, v);
            m[v] = max(m[v], m[u] + 1);
        }
        ans += mi(1) * m[v] / 2;
    };
    dfs(dfs, 0, -1);
    cout << int(ans * pw(2, n)) << '\n';
}

signed main()
{
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int T; cin >> T;
    while(T--) solve();
    return 0;
}

// Formulation:
// sum / 2^n = E[F(A)] (definition of expectation value = sum of RV F(A) / total number of outcomes of the event) => sum = 2^n * E[F(A)] so we focus on E[F(A)]
// F(A) = sum(F_i(A)), where F_i(A) = sum produced by node i
// F_i(A) = sum(X_t), X_t = indicator RV whether after round t, the node is 1 or not. E(F_i(A)) = sum(E(X_t))
// X_t = xor of all the elements in the subtree of u at a dist exactly = t in the original t = 0 tree, which is say x, also define d_i as the longest path in the subtre of node i
// E[X_t] = 1 / 2 when t <= d_i, 0 otherwise (since E of an arbitrary non zero amount of bools is 1/2), if we exceeed d_i, no nodes are there 
// E[F_i(A)] = d_i / 2 => E(F(A)) = sum(d_i) / 2
