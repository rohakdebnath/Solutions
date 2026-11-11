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
    int n, k; cin >> n >> k;
    vector<vector<int>> adj (n);
    for (int i = 0; i < n - 1; ++i) {
        int a, b; cin >> a >> b;
        --a, --b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    if (k % 2) {
        cout << "1\n";
        return;
    }
    vector<mi> e (n);
    vector<int> s(n); // e[i] = probablity that there are exactly k / 2 nodes in the subtree of edge i, edge i is the parent edge of node i. s[i] = nodes in the subtree of edge i

    auto dfs = [&] (auto&& self, int v, int p) -> void{
        s[v] = 1;
        for (int u: adj[v]) {
            if (u == p) continue;
            self(self, u, v);
            s[v] += s[u];
        }
        e[v] = ncr(s[v], k / 2) * ncr(n - s[v], k / 2) / ncr(n, k);
    };
    dfs(dfs, 0, -1);
    mi ans = 1;
    for (int i = 1; i < n; ++i) {
        ans += e[i];
    }
    cout << int(ans) << '\n';
}

signed main()
{
    ios::sync_with_stdio(false); cin.tie(nullptr);
    prefact();
    solve();
    return 0;
}
// notes:
// firstly formulate the E(number of valid nodes) as sum of indicator variables = 0 if node i is bad, 1 if good, then E[sum] = sig(E[i] = p(i)), p[i] = probablity that node i is one of the closest nodes
// Given: k special nodes in a tree and we have to find the closest nodes
// in case k is odd, there is only one arrangement which makes a node special, but its not true that there is only one arrangement where node i is special, examples are plenty, 
// however we can directly say E(sum | k = odd) = 1 by definition, without calcing the probs of each node being good
// in case k is even we still need to find E(sum | k = even) using the formulation, ie, sig(p[i]) , therefore net answer = sig(p[i])
// it is difficult to find p[i], but much easier to find e[i] = prob that edge i is a good edge (i.e subtree has k / 2 special nodes) therefore we have to reformulate E
// E[good nodes] = E[good edges + 1], since all the good edges will be connected (cant prove but intuitive) = 1 + E[good nodes] = 1 + sig(e[i]), where e[i] = edge i is good
// in k % 2 == 0, turns out that an edge i is good when there are exactly k / 2 special nodes in it's subtree.
