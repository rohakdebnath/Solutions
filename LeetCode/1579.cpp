#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

template <typename T = int>
class DSU {
private:
    vector<T> parent;
    vector<int> s;

public:
    DSU(T n) : parent(n), s(n, 1) {
        iota(parent.begin(), parent.end(), 0);
    }

    T find(T x) {
        while (x != parent[x]) {
            x = parent[x] = parent[parent[x]];
        }
        return x;
    }

    bool merge(T x_, T y_) {
        T x = find(x_);
        T y = find(y_);

        if (x == y) return false; 

        if (s[x] < s[y]) {
            parent[x] = y;
            s[y] += s[x];
        } else {
            parent[y] = x;
            s[x] += s[y];
        };
        return true;
    }

    bool connected(T x, T y) {
        return find(x) == find(y);
    }

    int size (int x) {
        return s[find(x)];
    }
};

void solve() {
    int n, m; cin >> n >> m;
    DSU dsu1(n), dsu2(n);
    int ans = 0;
    map<int, vector<array<int, 2>>> edge;
    for (int i = 0; i < m; ++i) {
        int t, u, v; cin >> t >> u >> v; --u, --v;
        edge[t].push_back({u, v});
    }
    for (auto [u, v]: edge[3]) {
        if (!dsu1.merge(u, v)) ++ans;
        if (!dsu2.merge(u, v)) ++ans;
    }
    for (auto [u, v]: edge[1]) {
        if (!dsu1.merge(u, v)) ++ans;
    }
    for (auto [u, v]: edge[2]) {
        if (!dsu2.merge(u, v)) ++ans;
    }

    cout << (dsu1.size(0) == n and dsu2.size(0) == n ? ans: -1) << '\n';
}

signed main()
{
    ios::sync_with_stdio(false); cin.tie(nullptr);
    solve();
    return 0;
}
