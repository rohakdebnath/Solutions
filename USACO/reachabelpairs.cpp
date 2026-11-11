#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

template <typename T = i64>
class DSU {
private:
    vector<T> parent;
    vector<i64> s;

public:
    DSU(T n) : parent(n), s(n, 0) {
        iota(parent.begin(), parent.end(), 0);
    }

    T find(T x) {
        while (x != parent[x]) {
            x = parent[x] = parent[parent[x]];
        }
        return x;
    }

    i64 merge(T x_, T y_) {
        T x = find(x_);
        T y = find(y_);

        if (x == y) return 0; 
        i64 ans = s[x] * s[y];
        if (s[x] < s[y]) {
            parent[x] = y;
            s[y] += s[x];
        } else {
            parent[y] = x;
            s[x] += s[y];
        };
        return ans;
    }

    bool connected(T x, T y) {
        return find(x) == find(y);
    }

    i64 size (i64 x) {
        return s[find(x)];
    }

    void set (i64 x) {
        s[find(x)] += 1;
    }
};

void solve() {
    i64 n, m; cin >> n >> m;
    string s; cin >> s;
    vector<vector<i64>> adj (n);
    for (i64 i = 0; i < m; ++i) {
        i64 a, b; cin >> a >> b; --a, --b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    DSU dsu (n);
    for (i64 i = 0; i < n; ++i) if (s[i] == '1') {
        for (i64 j: adj[i]) if (s[j] == '1') {
            dsu.merge(i, j);
        }
    }

    vector<i64> f(n);
    i64 ans = 0;
    for (i64 i = n - 1; i >= 0; --i) {
        if (s[i] == '1') {
            ans += dsu.size(i);
            dsu.set(i);
        } else {
            dsu.set(i);
            for (i64 j : adj[i]) {
                if (dsu.size(j) > 0 or s[j] == '1') ans += dsu.merge(i, j);
            }
        }
        f[i] = ans;
    }

    for (i64 i = 0; i < n; ++i) {
        cout << f[i] << "\n";
    }
}

signed main()
{
    ios::sync_with_stdio(false); cin.tie(nullptr);
    solve();
    return 0;
}
