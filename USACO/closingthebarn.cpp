#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

void setIO(string name = "")
{
    if (!name.empty()) {
        freopen((name + ".in").c_str(), "r", stdin);
        freopen((name + ".out").c_str(), "w", stdout);
    }
}

template <typename T = int>
class DSU {
private:
    vector<T> parent;
    vector<int> s, next;

public:
    DSU(T n) : parent(n), s(n, 0), next (n) {
        iota(parent.begin(), parent.end(), 0);
        iota(next.begin(), next.end(), 1); // next[i] = returns the nearest right element which is not a part of the set
    }

    T find(T x) {
        while (x != parent[x]) {
            x = parent[x] = parent[parent[x]];
        }
        return x;
    }

    bool merge(T x_, T y_) {
        if (s[y_] == 0) return false;
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

    int march (T x) {
        if (next[x] < next.size() and find(next[x]) == find(x)) next[x] = march(next[x]); 
        return next[x];
    }

    int size(int x) {
        return s[find(x)];
    }
    void set(int x) {
        s[x] = 1;
    }
};

signed main()
{
    ios::sync_with_stdio(false); cin.tie(nullptr);
    setIO("closing");
    int n, m; cin >> n >> m;
    vector<vector<int>> adj (n);
    for (int i = 0; i < m; ++i) {
        int a, b; cin >> a >> b;
        --a, --b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    vector<int> a (n); for (int i = 0; i < n; ++i) cin >> a[i], --a[i];
    DSU dsu (n);

    vector<int> ans (n);
    for (int i = n - 1; i >= 0; --i) {
        dsu.set(a[i]);
        for (int j: adj[a[i]]) {
            dsu.merge(a[i], j);
        }
        ans[i] = (dsu.size(a[i]) == n - i);
    }

    for (int i = 0; i < n; ++i) {
        cout << (ans[i] ? "YES\n": "NO\n");
    }
    return 0;
}
